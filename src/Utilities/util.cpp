#include<Glewy/Utilities/util.hpp>

#include<SML/vec.hpp>

#include<cmath>

namespace gly
{

namespace Util
{

float magnitude(const sml::vec2& v)
{return sqrt((v.x*v.x)+(v.y*v.y));}

sml::vec2 normalized(const sml::vec2& v)
{
	float mag = magnitude(v);
	if(mag == 0.0f){return sml::vec2(0.0f,0.0f);}
	return v / mag;
}

std::list<sml::vec2> PointsBetween(const sml::vec2& a, const sml::vec2& b, const int& num)
{
	sml::vec2 jump = (b-a) * (1.0f/((float)(num-1)));
	std::list<sml::vec2> list;
	for(int i = 0; i<num; i++)
	{
		list.push_back(a+(jump*i));
	}
	return list;
}	

float DegToRad(const float& deg)
{
	return deg * PI_DIV_180;
}

float RadToDeg(const float& rad)
{
	return rad * l80_DIV_PI;
}

} 

}