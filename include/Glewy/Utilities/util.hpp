#ifndef GLEWY_UTIL_HPP
#define GLEWY_UTIL_HPP

#include<list>
namespace sml{
    class vec2;
}

namespace gly
{

namespace Util
{

const float PI = 3.14159265359f;
const float PI_DIV_180 = 0.01745329251f;
const float l80_DIV_PI = 57.2957795131f; 

float magnitude(const sml::vec2&);
sml::vec2 normalized(const sml::vec2&);
std::list<sml::vec2> PointsBetween(const sml::vec2&, const sml::vec2&, const int&);

float DegToRad(const float&);
float RadToDeg(const float&);

} 

} 

#endif