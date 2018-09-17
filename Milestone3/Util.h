//
// Created by deni on 1/8/18.
//

#ifndef M2_UTIL_H
#define M2_UTIL_H

#include <string>
#include <vector>

void csvRead(std::vector< std::vector<std::string> > &data,char* fileName, char delim );
void printData (std::vector< std::vector<std::string> >);
bool isValidTaskName(std::string);
bool isValidSlot(int);
void parse(std::string &entry);

#endif //M2_UTIL_H
