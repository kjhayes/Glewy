#ifndef GLEWY_RAT_HPP
#define GLEWY_RAY_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

template<class T>
class Ray2{
public:
    vec2<T> origin;
    vec2<T> dir;

    Ray2(const vec2<T>& o, const vec2<T>& d):origin(o),dir(d){}
};

}

#endif