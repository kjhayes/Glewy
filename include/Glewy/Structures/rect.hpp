#ifndef GLEWY_VECPAIR_HPP
#define GLEWY_VECPAIR_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

static vec2<gly_float> UnitCorner[4];

template<class T>
struct Rect{
public:
    vec2<T> center;
    vec2<T> dimensions;

    Rect():center(0,0),dimensions(1.0f,1.0f){}
    Rect(const vec2<T>& cen):center(cen),dimensions(1.0f,1.0f){}
    Rect(const vec2<T>& cen, const vec2<T>& dim):center(cen),dimensions(dim){}

    vec2<T> GetCorner(const CORNER& corner){
        return center + {UnitCorner[corner].x*dimensions.x, UnitCorner[corner].y*dimensions.y}; 
    }
};

}

#endif