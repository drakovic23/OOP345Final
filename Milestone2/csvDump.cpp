#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Util.h"
#include "Task.h"
#include "TaskManager.h"



int main()
{
    std::vector< std::vector< std::string> > data;
    csvRead(data,"test.dat",'|');

    TaskManager taskM;

    for(int x = 0; x < data.size();x++)
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

    taskM.taskGraph();


    return 0;
}

/*
 *     for(int x = 0; x < data.size();x++)
    {
        for(int xx = 0; xx < data[x].size(); xx++)
        {
            std:: cout << data[x][xx] << ' ';
        }

        std::cout << '\n';

    }

 */