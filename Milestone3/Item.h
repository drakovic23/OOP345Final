//
// Created by deni on 1/8/18.
//

#ifndef MILESTONE3_ITEM_H
#define MILESTONE3_ITEM_H

#include <string>
#include <cstdlib>
#include <iostream>

class Item
{
    std::string itemName;
    std::string installTask;
    std::string removeTask;
    int secCode;
    std::string iDescription;

public:

    std::string graphString();
    void itemParser(std::string itemName = "", std::string installTask = "", std::string removeTask = "",
                    int secCode = 0, std::string description = "");

};

#endif //MILESTONE3_ITEM_H
