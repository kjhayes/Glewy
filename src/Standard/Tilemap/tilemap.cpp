#include<Glewy/Standard/Tilemap/tilemap.hpp>

#include<iostream>

namespace gly{

Tilemap::Tilemap(){
    active_tiles = new std::list<TileCache*>();
}
Tilemap::~Tilemap(){
    for(auto iter = active_tiles->begin(); iter != active_tiles->end(); iter++){
        delete (*iter);
    }
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
                active_tiles->remove((*iter));
                delete (*iter);
            }
            return;
        }
    }
}

}