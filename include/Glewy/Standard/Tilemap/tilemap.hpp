#ifndef GLEWY_TILEMAP_HPP
#define GLEWY_TILEMAP_HPP

#include<set>

#include<Glewy/Core/typedef.hpp>
#include<Glewy/Standard/Tilemap/tile.hpp>
#include<Glewy/Content/asset.hpp>

#include<substd/vec.hpp>
#include<substd/cache.hpp>
#include<substd/util.hpp>
#include<substd/cellmap.hpp>

namespace gly{

typedef ss::VectorCache<Tile*, ss::vec2<gly_int>> TileCache;

class Grid;

class Tilemap {
friend class TilemapRenderer;
protected:
    std::list<TileCache*>* active_tiles;

public:
    Tilemap();
    ~Tilemap();

    TileCache* GetCache(Tile* tile);

    void SetTile(Tile* tile, const ss::vec2<gly_int>& pos);
    void RemoveTile(Tile* tile, const ss::vec2<gly_int>& pos);

    void SetGrid(Tile* tile, Grid* grid);
    void LayerGrid(Tile* tile, Grid* grid);

    void Clear();
    void Clear(Tile*);
};

}

#endif