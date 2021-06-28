#ifndef GLEWY_TILE_HPP
#define GLEWY_TILE_HPP

#include<Glewy/Content/asset.hpp>

namespace gly{

class Texture;
class UVTable;

struct Tile {
public:
    Texture* texture;
    UVTable* uvtable;
    int index_in_table;

    Tile(Texture*, UVTable*, const int& index);

    //void LoadFromData(const Data&) override;
};

}

#endif