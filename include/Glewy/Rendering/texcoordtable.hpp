#ifndef GLEWY_TEXCOORDTABLE_HPP
#define GLEWY_TEXCOORDTABLE_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

struct TexCoord{
public:
    vec2<gly_float> size;
    vec2<gly_float> offset;
};

class TexCoordTable{
public:
    const int size;
    TexCoord* const coords;

    TexCoordTable(const int& size);
    ~TexCoordTable();

    void Grid(const vec2<gly_int>& cells, CORNER = BOTTOM_LEFT, bool rows = true);
};

}

#endif //GLEWY_TEXTURECOORDTABLE_HPP