#ifndef GLEWY_UVCOORDTABLE_HPP
#define GLEWY_UVTABLE_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

struct UVCoord{
public:
    vec2<gly_float> size;
    vec2<gly_float> offset;
};

class UVTable{
public:
    const int size;
    UVCoord* const coords;

    UVTable(const int& size);
    ~UVTable();

    void Grid(const vec2<gly_int>& cells, CORNER = BOTTOM_LEFT, bool rows = true);
};

}

#endif //GLEWY_TEXTURECOORDTABLE_HPP