//
// Created by deni on 1/8/18.
//

#ifndef MILESTONE3_ORDER_H
#define MILESTONE3_ORDER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "Item.h"

class Order
{
    std::string custName;
    std::string prodName;
    std::vector<std::string> itemList;
public:

    std::string graphString();
    void orderParser(std::vector<std::string> entries);

};

#endif //MILESTONE3_ORDER_H
