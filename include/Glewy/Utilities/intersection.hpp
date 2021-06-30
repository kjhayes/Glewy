#ifndef GLEWY_INTERSECTION_HPP
#define GLEWY_INTERSECTION_HPP

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Structures/rect.hpp>
#include<Glewy/Structures/ray.hpp>
#include<Glewy/Utilities/math.hpp>

namespace gly{

template<class T>
bool Overlap(const Rect<T>& a, const Rect<T>& b){
    vec2<T> ac = a.GetCorner(BOTTOM_LEFT);
    vec2<T> bc = b.GetCorner(BOTTOM_LEFT);
    if(
        (ac.x < bc.x + b.dimensions.x) &&
        (bc.x < ac.x + a.dimensions.x) &&
        (ac.y < bc.y + b.dimensions.y) &&
        (bc.y < ac.y + a.dimensions.y)
    ){return true;}
    else{return false;}
}

template<class T>
bool Overlap(const Ray<T>& ray, const Rect<T>& rect){
    vec2<T> bl_time = (rect.GetCorner(BOTTOM_LEFT) - ray.GetOrigin()); //Distance;
    vec2<T> tr_time = (rect.GetCorner(TOP_RIGHT) - ray.GetOrigin()); //Distance;
    vec2<T> inv_dir = 1.0f/ray.GetDirection();
    bl_time.x *= inv_dir.x;
    bl_time.y *= inv_dir.y;
    tr_time.x *= inv_dir.x;
    tr_time.y *= inv_dir.y;
    vec2<T> near;
    vec2<T> far;
    if(bl_time.x < tr_time.x){near.x = bl_time.x;far.x = tr_time.x;}
    else{near.x = tr_time.x; far.x = bl_time.x;}
    if(bl_time.y < tr_time.y){near.y = bl_time.y; far.y = tr_time.y;}
    else{near.y = tr_time.y; far.y = bl_time.y;}
    
    if(near.x > far.y || near.y > far.x){return false;}
    near.x = Math::Max<T>(near.x, near.y);
    far.x = Math::Max<T>(far.x, far.y);
    if(near.x >= 1 || far.x <= 0){return false;}
    return true;
}

template<class T>
T LinearRayHit(const T& origin, const T& magnitude, const T& wall_pos){
    if(!Math::InclusiveBetween(origin,magnitude,wall_pos)){return magnitude;}
    else{return wall_pos-origin;}
}

}

#endif