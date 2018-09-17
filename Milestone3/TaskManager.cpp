//
// Created by deni on 1/8/18.
//
#include <vector>
#include <iostream>
#include <fstream>

#include "TaskManager.h"


void TaskManager::printTaskList() //Prints data to console
{
    //loop through and print
    for(auto x = 0;x < taskList.size();x++)
    {
        taskList[x].taskPrint();
    }
}

void TaskManager::taskGraph()
{

    std::string cmd = "dot -Tpng taskGraph.gv > taskGraph.gv.png";

    std::string graph = "digraph task {";
    for(auto x = 0;x < taskList.size();x++)
    {
        graph += taskList[x].graphString();

    }

    graph += "\n"
            "}";


    std::ofstream file("taskGraph.gv");
    if(file)
    {
        file << graph;
    }
    else
    {
        std::cout << "Error opening file \n";
        exit(1);
    }

    std::system(cmd.c_str());

}