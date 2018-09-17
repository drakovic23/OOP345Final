//
// Created by deni on 1/8/18.
//

#include "Order.h"
#include "Util.h"

void Order::orderParser(std::vector<std::string> entries)
{

    if(entries.size() > 2)
    {
        //parse(entries[0]);
        //parse(entries[1]);
       // if(isValidTaskName(entries[0]))
            this->custName = entries[0];
        //else
          //  std::cout << "Syntax error in custName:" << entries[0] << '\n';
        //if(isValidTaskName(prodName))
            this->prodName = entries[1];
      // else
          //  std::cout << "Syntax error in prodName:" << entries[1] << '\n';

        for(int x = 2; x < entries.size();x++)
        {
            //parse(entries[x]);
           // if(isValidTaskName(entries[x]))
                this->itemList.push_back(entries[x]);
            //else
               // std::cout << "Syntax error in item:" << entries[x] << '\n';
        }

    }
    else
    {
        std::cout << "Syntax error in order, must be at least 3 fields\n";
    }

}

std::string Order::graphString()
{
    std::string fieldLine;

    /*  if(taskName.length() > 0 && taskPassed.length() < 1 && taskFailed.length() < 1) //node
      {
          fieldLine = "\n\"" + taskName + "\"" + "[shape=box]";

          return fieldLine;
      }*/

    for(const auto aItem: itemList)
    {


        if(custName.length() > 0 )
        {
           fieldLine += "\n\"" + custName + "\n" + prodName + "\"" + "->";
        }
        if(!itemList.empty())
        {
           fieldLine +=  "\"Item\n" + aItem + "\"" + "[color=blue]";
        }

    }

    return fieldLine;

}
