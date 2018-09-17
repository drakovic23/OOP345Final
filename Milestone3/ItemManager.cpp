//
// Created by deni on 1/8/18.
//

#include "ItemManager.h"



void ItemManager::itemGraph()
{
    std::string cmd = "dot -Tpng itemGraph.gv > itemGraph.gv.png";

    std::string graph = "digraph itemGraph {";
    for(auto x = 0;x < itemList.size();x++)
    {
        graph += itemList[x].graphString();

    }

    graph += "\n"
            "}";


    std::ofstream file("itemGraph.gv");
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
