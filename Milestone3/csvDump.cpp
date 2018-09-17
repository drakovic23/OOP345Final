#include <iostream>
#include <vector>
#include <fstream>

#include "Util.h"
#include "TaskManager.h"
#include "ItemManager.h"
#include "OrderManager.h"

int main()
{
    std::vector< std::vector< std::string> > data;
    //csvRead(data,"items.dat",'|');

    TaskManager taskM;
    ItemManager itemM;
    OrderManager orderM;

    csvRead(data,"items.dat", '|');

    for(int x=0; x < data.size();x++) //push items to item vector
    {
        Item aItem;

        if(data[x].size() == 5)
            aItem.itemParser(data[x][0],data[x][1], data[x][2], atoi(data[x][3].c_str()) ,data[x][4]);

        if(data[x].size() == 4)
            aItem.itemParser(data[x][0],data[x][1], data[x][2], atoi(data[x][3].c_str()));

        if(data[x].size() == 3)
            aItem.itemParser(data[x][0],data[x][1], data[x][2]);

        if(data[x].size() == 2)
            aItem.itemParser(data[x][0],data[x][1]);

        if(data[x].size() == 1)
            aItem.itemParser(data[x][0]);

        itemM.itemList.push_back(aItem);
    }

    itemM.itemGraph(); //Graph items

    data.clear();
    csvRead(data,"test.dat",'|'); //tasks

    for(int x = 0; x < data.size();x++) //push tasks to our taskmanager
    {
        Task aTask;
        if(data[x].size() == 4)
        {
            aTask.taskParser(data[x][0], atoi(data[x][1].c_str()), data[x][2], data[x][3]);
        }
        if(data[x].size() == 3)
        {
            aTask.taskParser(data[x][0], atoi(data[x][1].c_str()), data[x][2]);

        }
        if(data[x].size() == 1)
        {
            aTask.taskParser(data[x][0]);
        }

        taskM.taskList.push_back(aTask);
        //std::cout << '\n';
    }
    //std::cout << data[11][0] << std::endl;
    taskM.taskGraph(); //graph tasks

    data.clear();
    csvRead(data,"orders.dat", '|');
    //std::cout << data[0][1] << std::endl;
    for(int x = 0; x < data.size();x++)
    {
        Order aOrder;
        aOrder.orderParser(data[x]);
        orderM.orderList.push_back(aOrder);
    }

    orderM.orderGraph(); // Graph orders


    return 0;
}