#ifndef GLEWY_RAY_HPP
#define GLEWY_RAY_HPP

#include<SML/sml.hpp>

namespace gly
{

class Ray2D
{
    public:
    sml::vec2 origin;
    sml::vec2 dir;
};

class Ray3D
{
    public:
    sml::vec3 origin;
    sml::vec3 direction;
};

/*
bool Intersection(const Ray2D& a, const Ray2D& b, sml::vec2& point)
{
    float denominator = (a.dir.x*b.dir.y) - (a.dir.y*b.dir.x);
    if(denominator==0.0f){return false;}


    sml::vec2 o_dif = a.origin - b.origin;

    float t_numerator = (o_dif.y*b.dir.x) - (o_dif.x*b.dir.y);

    float u_numerator = (a.dir.x*o_dif.y) - (a.dir.y*o_dif.x);

    if(denominator>0.0f)
    {
        if((t_numerator<0.0f) || (u_numerator<0.0f)){return false;}
        if((t_numerator>denominator) || (u_numerator>denominator)){return false;}
    }
    else
    {
        if((t_numerator>0.0f) || (u_numerator>0.0f)){return false;}
        if((t_numerator<denominator) || (u_numerator<denominator)){return false;}
    }

    point = a.origin + (a.dir*(t_numerator/denominator));

    return true;
}
*/

}


#endif