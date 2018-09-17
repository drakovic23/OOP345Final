//
// Created by deni on 1/8/18.
//
#include <memory>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "TaskManager.h"
#include "Task.h"

std::string cmd = "dot -Tpng graph.gv > graph.gv.png";

TaskManager::TaskManager()
{
    taskList.clear();
}



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
    std::string graph = "digraph task {";
    for(auto x = 0;x < taskList.size();x++)
    {
        graph += taskList[x].graphString();

    }

    graph += "\n"
            "}";


    std::ofstream file("graph.gv");
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