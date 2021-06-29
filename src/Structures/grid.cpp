#include<Glewy/Structures/grid.hpp>

#include<Glewy/Content/stringserial.hpp>
#include<algorithm>

namespace gly{

Grid::Grid(const Data& d){LoadFromData(d);}
Grid::Grid(const File& f){LoadFromFile(f);}

void Grid::LoadFromData(const Data& d){
    std::string s_data(reinterpret_cast<const char*>(d.data), d.size);
    int s_pos = 0;
    while(s_pos<s_data.length()){
        int end_of_section = PositionOfNextMarker(s_data, s_pos+1, "vb", 2);
        
        switch (s_data[s_pos])
        {
        case 'v':{
            vec2<gly_int> v = StringTo<vec2<gly_int>>(s_data.substr(s_pos+1,end_of_section-(s_pos+1)));
            AddCoord(v);
            s_pos = end_of_section;
            break;
        }
        case 'b':{
            int c;
            vec2<gly_int>* vs = StringToArray<vec2<gly_int>>(s_data.substr(s_pos+1,end_of_section-(s_pos+1)), c, ' ');
            if(c >= 2){
                vec2<gly_int> dif = vs[1] - vs[0];
                for(int x = 0; x<=dif.x; x++){for(int y = 0; y<=dif.y; y++){
                    AddCoord({vs[0].x + x, vs[0].y + y});
                }}
            }
            else{
                std::cout<<"Error Loading Block Of Grid"<<std::endl;
            }
            delete vs;
            s_pos = end_of_section;
            break;
        }
        default:{s_pos++;}
        }
    }
}

void Grid::AddCoord(const vec2<gly_int>& c){
    coords.insert(c);
}
void Grid::RemoveCoord(const vec2<gly_int>& c){
    coords.erase(c);
}
bool Grid::GetCoord(const vec2<gly_int>& c){
    return coords.find(c)!=coords.end();
}

}