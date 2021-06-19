#ifndef GLEWY_FILE_HPP
#define GLEWY_FILE_HPP

#include<string>

namespace gly{

struct File{
public:
    File(char* file_name);
    char* file_name;
};

}

#endif