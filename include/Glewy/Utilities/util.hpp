#ifndef GLEWY_UTIL_HPP
#define GLEWY_UTIL_HPP

#include<list>
#include<Glewy/Structures/vec.hpp>

namespace gly
{

const float PI = 3.14159265359f;
const float PI_DIV_180 = 0.01745329251f;
const float l80_DIV_PI = 57.2957795131f; 

gly_float magnitude(const vec2<gly_float>&);
vec2<gly_float> normalized(const vec2<gly_float>&);
std::list<vec2<gly_float>> PointsBetween(const vec2<gly_float>&, const vec2<gly_float>&, const int&);

float DegToRad(const float&);
float RadToDeg(const float&);

} 

#endif