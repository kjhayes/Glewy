#ifndef GLEWY_TILEMAP_HPP
#define GLEWY_TILEMAP_HPP

#include<Glewy/Standard/Tilemap/tile.hpp>

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Structures/cache.hpp>

#include<Glewy/Utilities/util.hpp>
#include<unordered_map>

namespace gly{


typedef Cache<Tile*, vec2<gly_int>> TileCache;

//Tilemaps Must Only Contain Positive Points
class Tilemap{
friend class TilemapRenderer;
protected:
    std::list<TileCache*>* active_tiles;

public:
    Tilemap();
    ~Tilemap();

    void SetTile(Tile* tile, const vec2<gly_int>& pos);
    void RemoveTile(Tile* tile, const vec2<gly_int>& pos);
};

}

#endif