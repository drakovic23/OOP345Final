//
// Created by deni on 1/8/18.
//
#ifndef M2_TASKMANAGER_H
#define M2_TASKMANAGER_H

#include <vector>
#include <string>
#include "Task.h"

class TaskManager
{

public:
    std::vector<Task> taskList;
    TaskManager();
    void printTaskList();
    void taskGraph();

};

#endif //M2_TASKMANAGER_H
