//
// Created by deni on 1/8/18.
//
#include "Util.h"
#include <iostream>
#include <fstream>

//using  namespace std;

bool isValidSlot(int slot)
{
    if(slot >= 0 && slot <= 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidTaskName(const std::string tName) //Validates a taskname
{

    bool isFirstCharValid = (tName[0] >= 65 && tName[0] <= 90 //Capital chars
                             || tName[0] >= 97 && tName[0] <= 122 //Lower case chars
                             || tName[0] >= 48 && tName[0] <= 57 //Digits
                             || tName[0] == 95); // _

    //Validate first character of name
    if(isFirstCharValid)
    {
        int index = 1;
        while(index < tName.length())
        {
            if(tName[index] >= 65 && tName[index] <= 90 //Capital chars
               || tName[index] >= 97 && tName[index] <= 122 //Lower case chars
               || tName[index] >= 48 && tName[index] <= 57 //Digits
               || tName[index] == 95
               || tName[index] == ' '
               || tName[index] == 45) // -
            {

            }
            else
            {
                return false;
            }
            index++;

        }

        return true;

    }
    else
    {
        return false;
    }

    //return false;
}

void parse(std::string &entry)
{
    unsigned long int index = 0;

    while(entry[0] == ' ') entry.erase(0, 1);
    while(entry[entry.size()-1] == ' ') entry.erase(entry.size()-1,1);

}

void csvRead(std::vector< std::vector<std::string> > &data,char* fileName, char delim )
{
    std::vector<std::string> fields;
    //Our delim char

    //Get our delim character
    std::cout << "Delimiter is: " << delim << '\n';

    std::ifstream iFile(fileName);

    if (!iFile) {
        std::cerr << "Unable to open file \n";
        exit(1);
    }
    //Loop through our file

    std::string line;
    while (std::getline(iFile, line))
    {
        std::string entry;
        size_t loc = line.find('\r');

        if (loc != std::string::npos)
            line.erase(loc);

        int index = 0;
        while(index < line.length())
        {

            if(line[index] == delim)
            {
                index++; //skip delim
                //parse entry
                parse(entry);
                fields.push_back(entry); //push entry data
                entry.clear();
            }
            entry += line[index];
            index++;
        }
        if(entry.length() > 0)
        {
            fields.push_back(entry); // push final entry
        }
        data.push_back(std::move(fields)); //move vector of entries
    }

    //Create our tasks


}