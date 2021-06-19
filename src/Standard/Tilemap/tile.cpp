#include<Glewy/Standard/Tilemap/tile.hpp>

namespace gly{

Tile::Tile(Texture* tex, UVTable* uv, const int& index):texture(tex),uvtable(uv),index_in_table(index){}

}