#include<Glewy/Utilities/readfile.hpp>

#include<iostream>
#include<fstream>

namespace gly{

int ReadFile(const char* file_name, std::string& out){
    std::ifstream fileOS;
    fileOS.open(file_name);
    std::string line;
    if(fileOS.is_open())
        {
            while(std::getline(fileOS,line))
                {out.append(line+"\n");}
            fileOS.close();
        }
    else{std::cout<<"File "<<file_name<<" Failed To Open"<<std::endl;return 1;}
    return 0;
}

}