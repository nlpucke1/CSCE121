#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
using ::tolower;

bool isPalindrome(string PAL, int start_index, int end_index) //FIXME, won't return true
{
	cout << "Comparing: " << PAL.at(start_index) << " + " << PAL.at(end_index) << endl;
	cout << "Start index: " << start_index << endl;
	cout << "End index: " << end_index << endl; //Added this so you can see where it stops
	cout << endl;

	if(start_index >= end_index)
	{
		return true;
	}

	if(PAL.at(start_index) == PAL.at(end_index))
	{
		start_index = start_index + 1;
		end_index = end_index - 1;
		return isPalindrome(PAL, start_index, end_index);
	}

	return false; //Gives warning when I use else, says I might not be returning anything.

}

void removeSpaces(string &PAL) //This craziness removes spaces
{
	PAL.erase(std::remove(PAL.begin(),PAL.end(),' '),PAL.end());
}

void makeLowerCase(string &PAL) //Makes PAL lower case
{
	transform(PAL.begin(), PAL.end(), PAL.begin(), ::tolower);
}

int main(int argc, char *argv[])
{
    string FLAG = "";
    string PAL = "";
    int k = 0; //Used when determining if we're using a flag or not
    int start_index = 0;
    int end_index = 0;
    string temp = "";

    vector<string> allArgs(argv, argv + argc); //Vector of strings based on commandline
    temp = allArgs.at(1); //"./a.out" is allArgs.at(0)
    makeLowerCase(temp); //temp is either going to be a flag or the first word of the palindrome

    if(temp == "-cs" || temp == "-sc" || temp == "-c" || temp == "-s")
    {
    FLAG = temp; //This detects a flag
    k = 1; //Makes the for loop start after the flag
    }

    else
    k = 0; //Makes the for loop start after "./a.out" if there is no flag

    for(int i = k+1; i < allArgs.size(); i++) //Purpose of this for loop is to get the entire string for checking if it's a palindrome
    {
    	if(i == k+1)
    	{
    		PAL = allArgs.at(k+1);
    	}
    	else
    	{
    		PAL = PAL + " " + allArgs.at(i);
    	}
    }

    string original = PAL; //Used later. But we need it now since we might modify PAL

    if(FLAG == "-c") //Strings don't work with switch statements. Also I checked that the "-" is a part of the string.
    {
    	removeSpaces(PAL);
    }

    else if(FLAG == "-s")
    {
    	makeLowerCase(PAL);
    }

    else if(FLAG == "-cs" || FLAG == "-sc")
    {

    }

    else
    {
    	makeLowerCase(PAL);
    	removeSpaces(PAL);
    }

   if(isPalindrome(PAL, 0, (PAL.size() - 1))) //FIX ME: This is always returning false.
   {
   	cout << original << " is a palindrome." << endl;
   }

   else
   {
   		cout << original << " is not a palindrome." << endl;
   }

    return 0;
}
