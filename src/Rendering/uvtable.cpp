#include<Glewy/Rendering/uvtable.hpp>

#include<cstdlib>

namespace gly{

UVTable::UVTable(const int& size):size(size),coords(new UVCoord[size]){}

UVTable::~UVTable(){delete coords;}

void UVTable::Grid(const vec2<gly_int>& dim, CORNER corner, bool rows){
    vec2<gly_float> cell_size(1.0f/(float)dim.x,1.0f/(float)dim.y);

    vec2<gly_float> start;
    vec2<gly_float> mov;
    
    if(corner < 2){start.y = 0.0f; mov.y = cell_size.y;}//BOTTOM
    else{start.y = 1.0f-cell_size.y; mov.y = -cell_size.y;}//TOP
    if(corner & 1){start.x = 1.0f-cell_size.x; mov.x = -cell_size.x;}//RIGHT
    else{start.x = 0.0f; mov.x = cell_size.x;}//LEFT
    
    if(rows){
        int index = 0;
        for(int y = 0; y < dim.y; y++){
            for(int x = 0; x < dim.x; x++){
                if(index == size){return;}
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
                if(index == size){return;}
                coords[index].size = cell_size;
                coords[index].offset.x = (start.x + (x*mov.x));
                coords[index].offset.y = (start.y + (y*mov.y));
                index++;
            }
        }
    }
}

}