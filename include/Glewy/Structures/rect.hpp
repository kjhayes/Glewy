#ifndef GLEWY_VECPAIR_HPP
#define GLEWY_VECPAIR_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

const vec2<gly_float> UnitCorner[4] = {
    {-0.5f,-0.5f},
    {0.5f,-0.5f},
    {-0.5f,0.5f},
    {0.5f,0.5f}
};

template<class T>
struct Rect{
public:
    vec2<T> center;
    vec2<T> dimensions;

    Rect():center(0,0),dimensions(1.0f,1.0f){}
    Rect(const vec2<T>& cen):center(cen),dimensions(1.0f,1.0f){}
    Rect(const vec2<T>& cen, const vec2<T>& dim):center(cen),dimensions(dim){}

    vec2<T> GetCorner(const CORNER& corner) const {
        return center + vec2<T>(UnitCorner[corner].x*dimensions.x, UnitCorner[corner].y*dimensions.y); 
    }

    bool Overlap(const Rect<T>& other){
        vec2<T> bl = GetCorner(BOTTOM_LEFT);
        vec2<T> other_bl = other.GetCorner(BOTTOM_LEFT);
        if(
            (bl.x < other_bl.x + other.dimensions.x) &&
            (other_bl.x < bl.x + dimensions.x) &&
            (bl.y < other_bl.y + other.dimensions.y) &&
            (other_bl.y < bl.y + dimensions.y)
        ){return true;}
        else{return false;}
    }
};

}

#endif