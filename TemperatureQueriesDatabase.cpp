#include "TemperatureQueriesDatabase.h"
#include <vector>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;


void TemperatureDatabase::loadData(const string& filename)
{
    string location = "";
    int year = 0;
    int month = 0;
    double temperature = 0.0;
    ifstream infs(filename);
    if(infs.is_open())
    {
        std::string line;
        while (std::getline(infs, line))
        {
            std::istringstream iss(line);
            if (!(iss >> location >> year >> month >> temperature)) { cout << "error" << endl; } // error
            records.insert(location, year, month, temperature);
            //cout << '\t' << location<< '\t' << year<< '\t' << month<< '\t' << temperature;
            //cout << records << endl;
            //cout << "line ended" << '\n';
            iss.clear();
        }
        cout << records;
    }
}

void TemperatureDatabase::performQuery(const string& filename)
{
    int location = 0;
    int startYear = 0;
    int endYear = 0;
    string avgOrMode = "";

    ifstream infs(filename);
    if(infs.is_open())
    {
        std::string line;
        while(std::getline(infs, line))
        {
            std::istringstream iss(line);
            if(!(iss >> location >> avgOrMode >> startYear >> endYear )) { cout << "error" << endl; }
            ofstream ofs("result.dat"); //Creates output file
            ofs.open ("result.dat", std::ofstream::out | std::ofstream::app);
            ofs << location << " " << startYear << " " << endYear << " " << avgOrMode << " ";
            if(avgOrMode == "AVG")
            {
                ofs << getAverage(records, std::to_string(location), startYear, endYear) << endl;
            }
            if(avgOrMode == "MODE")
            {
                ofs << getMode(records, std::to_string(location), startYear, endYear) << endl;
            }
            ofs.close();
            iss.clear();
        }
    }
}

LinkedList TemperatureDatabase::getRecords() const
{
    return records;
}

string TemperatureDatabase::getAverage(LinkedList ll, string location, int startYear, int endYear) const
{
    Node* head = ll.getHead();
    Node* curr = head;
    string unknown = "Unknown";

    while(curr != nullptr)
    {
        if(curr->value == location && curr->year == startYear)
        {
            int count = 0;
            double total = 0;
            while(curr->year < endYear && curr->value == location)
            {
                count = count + 1;
                total = curr->temperature + total;
                curr = curr->next;
            }
            return to_string(total/count);
        }
        else
        {
            curr = curr->next;
        }
    }
    return unknown;

}

string TemperatureDatabase::getMode(LinkedList ll, string location, int startYear, int endYear) const
{
    Node* head = ll.getHead();
    Node* curr = head;
    string unknown = "Unknown";

    while(curr != nullptr)
    {
        if(curr->value == location && curr->year == startYear)
        {
            vector <int> temps;
            while(curr->year < endYear && curr->value == location)
            {
                int roundedTemp = round(curr->temperature);
                temps.push_back(roundedTemp);
            }
            sort(temps.begin(), temps.end());
            int cur_mode = temps.at(0);
            int mode_count = 0;
            int cur_number = temps.at(0);
            int cur_count = 1;
            for(int i = 0; i < temps.size(); i++)
            {
                if(temps.at(i) == cur_number)
                {
                    cur_count++;
                }
                else
                {
                    if(cur_count > mode_count)
                    {
                        cur_mode = cur_number;
                        mode_count = cur_count;
                    }
                    cur_count = 1;
                    cur_number = temps.at(i);
                }
            }
            return to_string(cur_mode);
        }
        else
        {
            curr = curr->next;
        }
    }
    return unknown;
}
