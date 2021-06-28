#include<Glewy/Standard/Tilemap/tile.hpp>

namespace gly{

Tile::Tile(Texture* tex, UVTable* uv, const int& index):texture(tex),uvtable(uv),index_in_table(index){}

/*
void Tile::LoadFromData(const Data& d){
    std::string str(reinterpret_cast<const char*>(d.data));
    int s_pos = 0;

    int end_of_section = PositionOfNextMarker(str, s_pos, ",", 1);
    std::string substr = str.substr(s_pos, end_of_section-s_pos);

    tex = Asset<Texture>::GetAsset()

    end_of_section = PositionOfNextMarker(str, s_pos, ",", 1);
    substr = str.substr(s_pos, end_of_section-s_pos);

    end_of_section = PositionOfNextMarker(str, s_pos, ",", 1);
    substr = str.substr(s_pos, end_of_section-s_pos);
     
}
*/

}