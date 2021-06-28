#ifndef GLEWY_TILEMAP_HPP
#define GLEWY_TILEMAP_HPP

#include<Glewy/Standard/Tilemap/tile.hpp>

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Structures/cache.hpp>

#include<Glewy/Utilities/util.hpp>

#include<Glewy/Content/asset.hpp>

namespace gly{

typedef Cache<Tile*, vec2<gly_int>> TileCache;

class Grid;

class Tilemap : public Asset<Tilemap> {
friend class TilemapRenderer;
protected:
    std::list<TileCache*>* active_tiles;

public:
    Tilemap();
    ~Tilemap();

    void SetTile(Tile* tile, const vec2<gly_int>& pos);
    void RemoveTile(Tile* tile, const vec2<gly_int>& pos);

    void SetGrid(Tile* tile, Grid* grid);
    void LayerGrid(Tile* tile, Grid* grid);

    void Clear();
    void Clear(Tile*);
};

}

#endif