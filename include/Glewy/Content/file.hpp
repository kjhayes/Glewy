#ifndef GLEWY_FILE_HPP
#define GLEWY_FILE_HPP

#include<string>

namespace gly{

struct File{
public:
    File(const char* file_name);
    const char* file_name;
};

}

#endif