#ifndef TEMP_DB
#define TEMP_DB

#include <string>
#include "LinkedList.h"

class TemperatureDatabase{
public:
    // Default constructor/destructor. Modify them if you need to.
    TemperatureDatabase(){}
    ~TemperatureDatabase(){}

    // The two functions below are required

    // Read the temperature records from the data file and populate the linked list
    void loadData(const std::string& data_file);

    // Read the queries from the query file and perform a series of queries
    void performQuery(const std::string& query_filename);

    LinkedList getRecords() const;

private:
    std::string getAverage(LinkedList, std::string location, int startYear, int endYear) const;
    std::string getMode(LinkedList, std::string location, int startYear, int endYear) const;
    LinkedList records;

};

#endif  // TEMP_DB
