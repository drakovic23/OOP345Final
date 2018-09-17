//
// Created by deni on 1/9/18.
//

#ifndef MILESTONE3_ORDERMANAGER_H
#define MILESTONE3_ORDERMANAGER_H

#include <fstream>

#include "Order.h"

class OrderManager
{
public:
    std::vector<Order> orderList;
    void orderGraph();

};

#endif //MILESTONE3_ORDERMANAGER_H
