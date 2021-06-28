#include<Glewy/Standard/Tilemap/tilemap.hpp>

#include<iostream>
#include<Glewy/Content/stringserial.hpp>
#include<Glewy/Structures/grid.hpp>

namespace gly{

Tilemap::Tilemap(){
    active_tiles = new std::list<TileCache*>();
}
Tilemap::~Tilemap(){
    Clear();
    delete active_tiles;
}

void Tilemap::SetTile(Tile* tile, const vec2<gly_int>& pos){
    for(auto iter = active_tiles->begin(); iter != active_tiles->end(); iter++){
        if((*iter)->grouper == tile){(*iter)->CacheThis(pos); return;}
    }
    TileCache* cache = new TileCache(tile); 
    active_tiles->push_back(cache);
    cache->CacheThis(pos);
}

void Tilemap::RemoveTile(Tile* tile, const vec2<gly_int>& pos){
    for(auto iter = active_tiles->begin(); iter != active_tiles->end(); iter++){
        if((*iter)->grouper == tile){
            (*iter)->DecacheThis(pos); 
            if((*iter)->IsEmpty()){
                delete (*iter);
                active_tiles->remove((*iter));
            }
            return;
        }
    }
}

void Tilemap::SetGrid(Tile* tile, Grid* grid){
    for(auto iter = active_tiles->begin(); iter != active_tiles->end(); iter++){
        if((*iter)->grouper == tile)
        {
            (*iter)->cache.clear();
            for(auto v = grid->coords.begin(); v != grid->coords.end(); v++){
                (*iter)->cache.push_back(*v);
            }
            return;
        }
    }
}
void Tilemap::LayerGrid(Tile* tile, Grid* grid){
    for(auto iter = active_tiles->begin(); iter != active_tiles->end(); iter++){
        if((*iter)->grouper == tile)
        {
            for(auto v = grid->coords.begin(); v != grid->coords.end(); v++){
                if(std::find((*iter)->cache.begin(), (*iter)->cache.end(), *v) == (*iter)->cache.end()){
                    (*iter)->cache.push_back(*v);
                }
            }
            return;
        }
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