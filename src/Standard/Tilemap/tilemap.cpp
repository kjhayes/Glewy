#include<Glewy/Standard/Tilemap/tilemap.hpp>

#include<iostream>
#include<Glewy/Content/stringserial.hpp>
#include<Glewy/Standard/Tilemap/grid.hpp>

namespace gly{

Tilemap::Tilemap(){
    active_tiles = new std::list<TileCache*>();
}
Tilemap::~Tilemap(){
    Clear();
    delete active_tiles;
}

TileCache* Tilemap::GetCache(Tile* tile){
    for(auto iter = active_tiles->begin(); iter != active_tiles->end(); iter++){
        if((*iter)->grouper == tile){return (*iter);}
    }
    TileCache* cache = new TileCache(tile);
    active_tiles->push_back(cache);
    return cache;
}

void Tilemap::SetTile(Tile* tile, const ss::vec2<gly_int>& pos){
    GetCache(tile)->CacheThis(pos);
}

void Tilemap::RemoveTile(Tile* tile, const ss::vec2<gly_int>& pos){
    TileCache* c = GetCache(tile);
    c->DecacheThis(pos);
    if(c->IsEmpty()){
        active_tiles->remove(c);
        delete c;
    }
}

void Tilemap::SetGrid(Tile* tile, Grid* grid){
    TileCache* c = GetCache(tile);
    c->cache.clear();
    c->cache.reserve(grid->coords.size());
    for(auto iter = grid->coords.begin(); iter != grid->coords.end(); iter++){
        c->cache.push_back(*iter);
    }
}
void Tilemap::LayerGrid(Tile* tile, Grid* grid){
    TileCache* c = GetCache(tile);
    std::set<ss::vec2<gly_int>> set(grid->coords);
    for(auto iter = c->cache.begin(); iter != c->cache.end(); iter++){
        set.insert((*iter));
    }
    c->cache.clear();
    c->cache.reserve(set.size());
    for(auto iter = set.begin(); iter != set.end(); iter++){
        c->cache.push_back(*iter);
    }
}

void Tilemap::Clear(){
    for(auto iter = active_tiles->begin(); iter != active_tiles->end(); iter++){
        delete (*iter);
    }
    active_tiles->clear();
}
void Tilemap::Clear(Tile* tile){
    for(auto iter = active_tiles->begin(); iter != active_tiles->end(); iter++){
        if((*iter)->grouper == tile)
        {
            delete (*iter);
            active_tiles->remove(*iter);
            return;
        }
    }
}

}