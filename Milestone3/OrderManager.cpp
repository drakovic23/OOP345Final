//
// Created by deni on 1/9/18.
//

#include "OrderManager.h"

void OrderManager::orderGraph()
{
    std::string cmd = "dot -Tpng orderGraph.gv > orderGraph.gv.png";

    std::string graph = "digraph itemGraph {";
    for(auto x = 0;x < orderList.size();x++)
    {
        graph += orderList[x].graphString();

    }

    graph += "\n"
            "}";


    std::ofstream file("orderGraph.gv");
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
