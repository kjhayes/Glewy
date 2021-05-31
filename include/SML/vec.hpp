#ifndef SML_VEC_HPP
#define SML_VEC_HPP

#include<iostream>

namespace sml
{
	
class vec2;
class vec3;
class vec4;
	
class vec2
{
public:
	union
	{
	struct {float x, y;};
	float array[2];
    };
	
	vec2(const vec2&);
	
	vec2(const float& = 0.0f, const float& = 0.0f);
	
	vec2(const float(&)[2]);
	
    vec2 Sum(const vec2&) const;    void Add(const vec2&);
    vec2 Dif(const vec2&) const;    void Sub(const vec2&);
    vec2 Prod(const float&) const;  void Mult(const float&);
    vec2 Quot(const float&) const;  void Div(const float&);

    float Dot(const vec2&) const;
    bool Equals(const vec2&) const;

    //operator overloading
    vec2 operator+(const vec2&) const;  void operator+=(const vec2&);
    vec2 operator-(const vec2&) const;  void operator-=(const vec2&);
    vec2 operator*(const float&) const; void operator*=(const float&);
    vec2 operator/(const float&) const; void operator/=(const float&);
    bool operator==(const vec2&) const;
    bool operator!=(const vec2&) const;

    friend std::ostream& operator<<(std::ostream&,const vec2&);
	
	explicit operator vec3() const;
	explicit operator vec4() const;
};

class vec3
{
public:
    union
	{
	struct {float x, y, z;};
    struct {float r, g, b;};
	float array[3];
    };
	
	vec3(const vec3&);
	
	vec3(const float& = 0.0f, const float& = 0.0f, const float& = 0.0f);

	vec3(const float(&)[3]);

	vec3(const vec2&, const float& = 0.0f);
	vec3(const float&, const vec2&);

    vec3 Sum(const vec3&) const;    void Add(const vec3&);
    vec3 Dif(const vec3&) const;    void Sub(const vec3&);
    vec3 Prod(const float&) const;  void Mult(const float&);
    vec3 Quot(const float&) const;  void Div(const float&);

    float Dot(const vec3&) const;
    vec3 Cross(const vec3&) const;
    bool Equals(const vec3&) const;

    //operator overloading
    vec3 operator+(const vec3&) const;  void operator+=(const vec3&);
    vec3 operator-(const vec3&) const;  void operator-=(const vec3&);
    vec3 operator*(const float&) const; void operator*=(const float&);
    vec3 operator/(const float&) const; void operator/=(const float&);
    bool operator==(const vec3&) const;
    bool operator!=(const vec3&) const;

    friend std::ostream& operator<<(std::ostream&,const vec3&);
	
	explicit operator vec2() const;
	explicit operator vec4() const;
};

class vec4
{
public:
    union
	{
	struct {float x, y, z, w;};
    struct {float r, g, b, a;};
	float array[4];
    };
	
	vec4(const vec4&);
	
    vec4(const float& = 0.0f, const float& = 0.0f, const float& = 0.0f, const float& = 0.0f);
	
	vec4(const float(&)[4]);
	
	vec4(const vec2&, const float& = 0.0f, const float& = 0.0f);
	vec4(const float&, const vec2&, const float& = 0.0f);
	vec4(const float&, const float&, const vec2&);
	vec4(const vec2&, const vec2&);
	
	vec4(const vec3&, const float& = 0.0f);
	vec4(const float&, const vec3&);
	
    vec4 Sum(const vec4&) const;    void Add(const vec4&);
    vec4 Dif(const vec4&) const;    void Sub(const vec4&);
    vec4 Prod(const float&) const;  void Mult(const float&);
    vec4 Quot(const float&) const;  void Div(const float&);

    float Dot(const vec4&) const;
    bool Equals(const vec4&) const;

    //operator overloading
    vec4 operator+(const vec4&) const;  void operator+=(const vec4&);
    vec4 operator-(const vec4&) const;  void operator-=(const vec4&);
    vec4 operator*(const float&) const; void operator*=(const float&);
    vec4 operator/(const float&) const; void operator/=(const float&);
    bool operator==(const vec4&) const;
    bool operator!=(const vec4&) const;
	
    friend std::ostream& operator<<(std::ostream&,const vec4&);
	
	explicit operator vec2() const;
	explicit operator vec3() const;
};

}
#endif // SML_VEC_HPP
