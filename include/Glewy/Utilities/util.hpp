#ifndef GLEWY_UTIL_HPP
#define GLEWY_UTIL_HPP

#include<list>
#include<Glewy/Structures/vec.hpp>
#include<Glewy/Core/typedef.hpp>

namespace gly
{

gly_float magnitude(const vec2<gly_float>&);
vec2<gly_float> normalized(const vec2<gly_float>&);
std::list<vec2<gly_float>> PointsBetween(const vec2<gly_float>&, const vec2<gly_float>&, const int&);

float DegToRad(const float&);
float RadToDeg(const float&);

} 

#endif