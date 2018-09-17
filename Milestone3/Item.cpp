//
// Created by deni on 1/8/18.
//

#include "Item.h"
#include "Util.h"

void Item::itemParser(std::string itemName, std::string installTask, std::string removeTask, int secCode, std::string description)
{

    int fields = 0;

    if(itemName.length() > 0)
        fields++;
    if(installTask.length() > 0)
        fields++;
    if(removeTask.length() > 0)
        fields++;
    if(secCode > 0)
        fields++;
    if(description.length() > 0)
        fields++;

    //Validate
    switch(fields)
    {
        case 5:
                if(description.length() > 1)
                {
                    parse(description); //temp fix
                    if (isValidTaskName(description))
                        this->iDescription = description;
                    else
                        std::cout << "Syntax error in description\n" << description << std::endl;
                }

        case 4:
                this->secCode = secCode;

        case 3:
            if(isValidTaskName(removeTask))
                this->removeTask = removeTask;
            else
                std::cout << "Syntax error in removeTask \n";

        case 2:
            if(isValidTaskName(installTask))
                this->installTask = installTask;
            else
                std::cout << "Syntax error in installTask \n";
        case 1:
            if(isValidTaskName(itemName))
                this->itemName = itemName;
            else
                std::cout << "Syntax error in itemName:" << itemName << "\n";
            break;

        default:
            std::cout << "Error, item must have 1, 2 ,3, 4 or 5 fields \n";

    }


}

std::string Item::graphString()
{
    std::string fieldLine;

  /*  if(taskName.length() > 0 && taskPassed.length() < 1 && taskFailed.length() < 1) //node
    {
        fieldLine = "\n\"" + taskName + "\"" + "[shape=box]";

        return fieldLine;
    }*/

    if(itemName.length() > 0 )
    {
        fieldLine.clear();
        fieldLine = "\n\"Item\n" + itemName +"\"" + "->";
    }
    if(installTask.length() > 0)
    {
        fieldLine += "\"Installer\n" + installTask + "\"" + " [color=green]";
    }
    if(removeTask.length() > 0)
    {
        fieldLine +=  "\n\"Item\n" + itemName + "\"" + "->" + "\"Remover\n" + removeTask + "\"" + "[color=red]";
    }

    return fieldLine;
}
