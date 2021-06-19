#ifndef GLEWY_AABB_HPP
#define GLEWY_AABB_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

struct AABB
{
    vec2<gly_float> Position;
    vec2<gly_float> Scale;
};

}

#endif