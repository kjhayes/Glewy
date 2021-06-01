#include<Glewy/Utilities/util.hpp>

#include<Glewy/Structures/vec.hpp>

#include<cmath>

namespace gly
{

float magnitude(const vec2<gly_float>& v)
{return sqrt((v.x*v.x)+(v.y*v.y));}

vec2<gly_float> normalized(const vec2<gly_float>& v)
{
	float mag = magnitude(v);
	if(mag == 0.0f){return vec2<gly_float>(0.0f,0.0f);}
	return v / mag;
}

std::list<vec2<gly_float>> PointsBetween(const vec2<gly_float>& a, const vec2<gly_float>& b, const int& num)
{
	vec2<gly_float> jump = (b-a) * (1.0f/((float)(num-1)));
	std::list<vec2<gly_float>> list;
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