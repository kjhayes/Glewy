#ifndef GLEWY_DATA_HPP
#define GLEWY_DATA_HPP

namespace gly{

struct Data{
public:
    Data(const int& s, unsigned char* d_addr);
    int size;
    unsigned char* data;
};


}

#endif