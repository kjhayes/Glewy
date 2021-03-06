#include<Glewy/Rendering/uvtable.hpp>

#include<Glewy/Content/stringserial.hpp>

#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>

namespace gly{

UVCoord::UVCoord():size({1.0f,1.0f}),offset({0.0f,0.0f}){}
UVCoord::UVCoord(const ss::vec2<gly_float>& size, const ss::vec2<gly_float>& offset):size(size),offset(offset){}

UVCoord* UVCoord::Grid(
    const int& size, 
    const ss::vec2<gly_int>& dim,
    const ss::CORNER& corner, 
    const bool& rows)
{
//
    UVCoord* coords = new UVCoord[size];

    ss::vec2<gly_float> cell_size(1.0f/(float)dim.x,1.0f/(float)dim.y);
    ss::vec2<gly_float> start;
    ss::vec2<gly_float> mov;

    if(corner < 2){start.y = 0.0f; mov.y = cell_size.y;}//BOTTOM
    else{start.y = 1.0f-cell_size.y; mov.y = -cell_size.y;}//TOP
    if(corner & 1){start.x = 1.0f-cell_size.x; mov.x = -cell_size.x;}//RIGHT
    else{start.x = 0.0f; mov.x = cell_size.x;}//LEFT

    if(rows){
        int index = 0;
        for(int y = 0; y < dim.y; y++){
            for(int x = 0; x < dim.x; x++){
                if(index == size){return coords;}
                coords[index].size = cell_size;
                coords[index].offset.x = (start.x + (x*mov.x));
                coords[index].offset.y = (start.y + (y*mov.y));
                index++;
            }
        }
    }
    else{
        int index = 0;
        for(int x = 0; x < dim.x; x++){
            for(int y = 0; y < dim.y; y++){
                if(index == size){return coords;}
                coords[index].size = cell_size;
                coords[index].offset.x = (start.x + (x*mov.x));
                coords[index].offset.y = (start.y + (y*mov.y));
                index++;
            }
        }
    }
    return coords;
}

UVTable::UVTable(const Data& data):size(0),coords(nullptr){LoadFromData(data);}
UVTable::UVTable(const File& file):size(0),coords(nullptr){LoadFromFile(file);}

void UVTable::LoadFromData(const Data& data){
    std::string s_data(reinterpret_cast<const char*>(data.data), data.size);
    std::vector<UVCoord> read_coords;
    int s_pos = 0;
    while(s_pos<s_data.length()){
        int end_of_section = PositionOfNextMarker(s_data, s_pos+1, "gc", 2);
        
        switch (s_data[s_pos])
        {
        case 'g':{
            int x;
            int* vals = StringToArray<int>(s_data.substr(s_pos+1,end_of_section-(s_pos+1)), x);
            if(x!=5){std::cerr<<"ERROR LOADING UVTABLE!"<<std::endl;}
            UVCoord* coord_arr = UVCoord::Grid(vals[0], {vals[1],vals[2]}, static_cast<ss::CORNER>(vals[3]), (bool)vals[4]);
            for(int i = 0; i < vals[0]; i++){
                read_coords.push_back(coord_arr[i]);
            }
            delete coord_arr;
            delete vals;
            s_pos = end_of_section;break;
        }
        case 'c':{
            int x;
            float* vals = StringToArray<float>(s_data.substr(s_pos+1,end_of_section-(s_pos+1)), x);
            if(x!=4){std::cerr<<"ERROR LOADING UVTABLE!"<<std::endl;}
            read_coords.push_back({{vals[0],vals[1]},{vals[2],vals[3]}});
            delete vals;
            s_pos = end_of_section;break;
        }
        default:{s_pos++;}
        }
    }
    //Actually Put The Data Into The Class' Scope Instead of Method Scope
    size = read_coords.size();
    coords = new UVCoord[size];
    memcpy(coords, read_coords.data(), size*sizeof(UVCoord));
}

UVTable::~UVTable(){delete coords;}

UVCoord* UVTable::GetCoords(){return coords;}
int UVTable::GetSize(){return size;}

void UVTable::Serialize(const char* file_name) {
    std::ofstream file(file_name);
    file.clear();
    for(int i = 0; i < size; i++){
        file<<"c,"<<coords[i].offset.x<<','<<coords[i].offset.y<<','<<coords[i].size.x<<','<<coords[i].size.y;
    }
    file.close();
}

}