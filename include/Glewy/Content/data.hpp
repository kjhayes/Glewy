#ifndef GLEWY_DATA_HPP
#define GLEWY_DATA_HPP

namespace gly{

struct Data{
public:
    Data(const int& s, const unsigned char* d_addr);
    int size;
    const unsigned char* data;
};


}

#endif