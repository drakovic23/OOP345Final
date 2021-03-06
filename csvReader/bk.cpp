
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector< std::vector<std::string> > data;

int main(int argc, char* argv[])
{
    if(argc > 1)
    {

        std::vector<std::string> fields;
        std::string fileName = argv[1];
        //Our delim char
        char delim = *argv[2];

        //Get our delim character
        std::cout << "Delimiter is: " << delim << '\n';

        std::ifstream iFile;
        iFile.open(fileName.c_str());

        if (!iFile) {
            std::cerr << "Unable to open file \n";
            exit(1);
        }
        //Loop through our file

        std::string line;
        while (std::getline(iFile, line))
        {
            int index = 0;
            std::string entry;

            size_t loc = line.find('\r');
            if (loc != std::string::npos) //returns npos if not found
            {
                line.erase(loc);
            }

            while (index < line.length())
            {

                //if(line[0] == ' ')
                //   line.erase(0);



                if (line[index] == ' ' && line[index + 1] == ' '
                    || line[index] == ' ' && line[index + 1] == delim
                    || line[index] == ' ' && line[index - 1] == delim)
                    index++; // skip useless characters


                if (line[index] == delim)
                {
                    if (entry.length() > 0)
                        fields.push_back(entry);
                    entry.clear();
                    index++; //skip the delim
                } else {
                    entry += line[index];
                    index++;
                }


                //std::cout << "Entry: " << entry << '\n';
            }
            //Push the last entry
            if (entry.length() > 0 && entry[0] > 47 && entry[0] < 123) //Check our last entry on line for possible junk @ EOF
                fields.push_back(entry);
            //Push our fields vector
            data.push_back(fields);
            //Clear for another loop
            fields.clear();
            entry.clear();
        }


        //Print our 2d vector out
        for (int x = 0; x < data.size(); x++)
        {
            std::cout << "* ";
            for (int xx = 0; xx < data[x].size(); xx++) {
                std::cout << data[x][xx] << " * ";
            }

            std::cout << '\n';
        }
    }
    else
    {
        std::cout << "Run the program with 2 command line arguments: [filename] & [delimiter]" << '\n';
    }


    return 0;
}
