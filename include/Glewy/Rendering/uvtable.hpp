#ifndef GLEWY_UVTABLE_HPP
#define GLEWY_UVTABLE_HPP

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Content/asset.hpp>
#include<Glewy/Content/serializable.hpp>

namespace gly{

struct UVCoord{
public:
    vec2<gly_float> size;
    vec2<gly_float> offset;

    UVCoord();
    UVCoord(const vec2<gly_float>& size, const vec2<gly_float>& offset);

    static UVCoord* Grid(
        const int& size, 
        const vec2<gly_int>& cells, 
        const CORNER& = BOTTOM_LEFT, 
        const bool& rows = true);
};

class UVTable : public Asset<UVTable>, public Serializable {
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

    void Serialize(const char* file_name) override;
};

}

#endif //GLEWY_TEXTURECOORDTABLE_HPP