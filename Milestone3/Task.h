//
// Created by deni on 1/8/18.
//

#ifndef M2_TASK_H
#define M2_TASK_H

#include <cstdlib>
#include <string>

class Task
{
    //Task(std::string, int, std::string, std::string);
public:
    std::string taskName;
    int taskSlots;
    std::string taskPassed;
    std::string taskFailed;

    std::string taskPrint();
    std::string graphString();

    void taskParser(std::string taskName = "", int taskSlots = 0, std::string taskPassed = "", std::string taskFailed = "");

};

#endif //M2_TASK_H
