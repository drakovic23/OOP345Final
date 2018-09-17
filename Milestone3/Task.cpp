//
// Created by deni on 1/8/18.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <memory>
#include <vector>
#include "Task.h"
#include "Util.h"

#include <vector>

std::string Task::graphString() //Returns a reference of a string array for graphing
{
    std::string fieldLine;

    if(taskName.length() > 0 && taskPassed.length() < 1 && taskFailed.length() < 1) //node
    {
        fieldLine = "\n\"" + taskName + "\"" + "[shape=box]";

        return fieldLine;
    }

    if(taskName.length() > 0 )
    {
        fieldLine.clear();
        fieldLine = "\n\"" + taskName +"\"" + "->";
    }
    if(taskPassed.length() > 0)
    {
        fieldLine += "\"" + taskPassed + "\"" + " [color=green]";
    }
    if(taskFailed.length() > 0)
    {
        fieldLine +=  "\n\"" + taskName + "\"" + "->" + "\"" + taskFailed + "\"" + "[color=red]";
    }

    return fieldLine;
}

std::string Task::taskPrint() //Returns a string of the task fields for console output
{
    std::string fieldLine;

    if(taskName.length() > 0 )
    {
        fieldLine += '*' + taskName + '*';
    }
    fieldLine += taskSlots;
    if(taskPassed.length() > 0)
    {
        fieldLine += '*' + taskSlots + '*';
    }
    if(taskFailed.length() > 0)
    {
        fieldLine += '*' + taskFailed + '*';
    }

    return fieldLine;
}

void Task::taskParser(std::string taskName, int taskSlots, std::string taskPassed, std::string taskFailed)
{
    int fields = 0;

    if(taskName.length() > 0)
        fields++;
    if(taskSlots > 0)
        fields++;
    if(taskPassed.length() > 0)
        fields++;
    if(taskFailed.length() > 0)
        fields++;

    if(fields == 1)
        taskSlots = 1;


    //Validate
    switch(fields)
    {
        case 4:
            if(isValidTaskName(taskFailed))
                this->taskFailed = taskFailed;
            else
                std::cout << "Syntax error in taskFailed \n";

        case 3:
            if(isValidTaskName(taskPassed))
                this->taskPassed = taskPassed;
            else
                std::cout << "Syntax error in taskpassed \n";

        case 2:
            if(isValidSlot(taskSlots))
                this->taskSlots = taskSlots;
            else
                std::cout << "Syntax error in taskSlots \n";
        case 1:
            if(isValidTaskName(taskName))
                this->taskName = taskName;
            else
                std::cout << "Syntax error in taskName \n";
            break;

        default:
            std::cout << "Error, task must have 1, 2 ,3 or 4 fields \n";

    }
}