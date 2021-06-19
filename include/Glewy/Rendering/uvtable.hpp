#ifndef GLEWY_UVTABLE_HPP
#define GLEWY_UVTABLE_HPP

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Content/asset.hpp>

namespace gly{

struct UVCoord{
public:
    vec2<gly_float> size;
    vec2<gly_float> offset;

    static UVCoord* Grid(const int& size, const vec2<gly_int>& cells, CORNER = BOTTOM_LEFT, bool rows = true);
};

class UVTable : public Asset<UVTable> {
    friend class Asset<UVTable>;
protected:
    int size;
    UVCoord* coords;

    UVTable(const Data& data);
    UVTable(const File& file);

    void LoadFromData(const Data& data) override;
    ~UVTable();

public:
    int GetSize();
    UVCoord* GetCoords();
};

}

#endif //GLEWY_TEXTURECOORDTABLE_HPP