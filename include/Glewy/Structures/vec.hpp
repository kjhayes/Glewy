#ifndef GLEWY_VEC_HPP
#define GLEWY_VEC_HPP

#include<iostream>
#include<Glewy/Core/typedef.hpp>

namespace gly
{

template<typename T> class vec3;
template<typename T> class vec4;
	
template<typename T> class vec2
{
public:
	union
	{
	struct {T x, y;};
	T array[2];
    };
	
    vec2(const T& x = (T)0.0f, const T& y = (T)0.0f):x(x), y(y){}
	vec2(const vec2<T>& other):x(other.x), y(other.y){}
	vec2(const T(&array)[2]):x(array[0]),y(array[1]){}
	
    vec2<T> Sum(const vec2<T>& other) const {return vec2<T>(x+other.x, y+other.y);};    
    void Add(const vec2<T>& other) {*this = this->Sum(other);}

    vec2<T> Dif(const vec2<T>& other) const {return vec2<T>(x-other.x, y-other.y);}
    void Sub(const vec2<T>& other) {*this = this->Dif(other);}
    
    vec2<T> Prod(const T& scalar) const {return vec2<T>(x*scalar, y*scalar);}
    void Mult(const T& scalar) {*this = this->Prod(scalar);}
    
    vec2<T> Quot(const T& scalar) const {return vec2<T>(x/scalar, y/scalar);}
    void Div(const T& scalar) {*this = this->Quot(scalar);}

    T Dot(const vec2<T>& other) const {return (x*other.x)+(y*other.y);}
    bool Equals(const vec2<T>& other) const {return ((x==other.x) && (y==other.y));}

    //operator overloading
    void operator=(const vec2<T>& other){x = other.x; y = other.y;}
    
    vec2<T> operator+(const vec2<T>& other) const {return Sum(other);}  
    void operator+=(const vec2<T>& other) {Add(other);}
    
    vec2<T> operator-(const vec2<T>& other) const {return Dif(other);}
    void operator-=(const vec2<T>& other) {Sub(other);}
    
    vec2<T> operator*(const T& scalar) const {return Prod(scalar);}
    void operator*=(const T& scalar) {Mult(scalar);}
    
    vec2<T> operator/(const T& scalar) const {return Quot(scalar);}
    void operator/=(const T& scalar) {Div(scalar);}
    
    bool operator==(const vec2<T>& other) const {return Equals(other);}
    bool operator!=(const vec2<T>& other) const {return !Equals(other);}

    friend std::ostream& operator<<(std::ostream& o,const vec2<T>& v)
    {o<<"("<<v.x<<", "<<v.y<<")";return o;}
	
	explicit operator vec3<T>() const {return vec3<T>(this->x, this->y);}
	explicit operator vec4<T>() const {return vec4<T>(this->x, this->y);}

    template<class O> operator vec2<O>() const {return vec2<O>((O)this->x, (O)this->y);}
};

template<typename T> class vec3
{
public:
    union
	{
	struct {T x, y, z;};
    struct {T r, g, b;};
	T array[3];
    };
	
    
    vec3(const T& x = (T)0.0f, const T& y = (T)0.0f, const T& z = (T)0.0f):x(x), y(y), z(z){}
    vec3(const vec3<T>& other):x(other.x), y(other.y), z(other.z){}
    vec3(const T(&array)[3]):x(array[0]),y(array[1]),z(array[2]){}
    vec3(const vec2<T>& front, const T& z):x(front.x), y(front.y), z(z){}
    vec3(const T& x, const vec2<T>& back):x(x), y(back.x), z(back.y){}
    
    vec3<T> Sum(const vec3<T>& other)const{return vec3<T>(x+other.x, y+other.y, z+other.z);}
    void Add(const vec3<T>& other){*this = this->Sum(other);}
    
    vec3<T> Dif(const vec3<T>& other)const{return vec3<T>(x-other.x, y-other.y, z-other.z);}
    void Sub(const vec3<T>& other){*this = this->Dif(other);}

    vec3<T> Prod(const T& scalar)const{return vec3<T>(x*scalar, y*scalar, z*scalar);}
    void Mult(const T& scalar){*this = this->Prod(scalar);}
    
    vec3<T> Quot(const T& scalar)const{return vec3<T>(x/scalar, y/scalar, z/scalar);}
    void Div(const T& scalar){*this = this->Quot(scalar);}

    T Dot(const vec3<T>& other)const {return (x*other.x)+(y*other.y)+(z*other.z);}
    vec3<T> Cross(const vec3<T>& other)const
    {return vec3<T>((y*other.z)-(z*other.y), (z*other.x)+(x*other.z), (x*other.y)+(y*other.x));}
    
    bool Equals(const vec3<T>& other)const{return ((x==other.x) && (y==other.y) && (z==other.z));}

    //operator overloading
    void operator=(const vec3<T>& other){x = other.x; y = other.y; z = other.z;}

    vec3<T> operator+(const vec3<T>& other)const{return Sum(other);}
    void operator+=(const vec3<T>& other){Add(other);}
    
    vec3<T> operator-(const vec3<T>& other)const{return Dif(other);}
    void operator-=(const vec3<T>& other){Sub(other);}
    
    vec3<T> operator*(const T& scalar)const{return Prod(scalar);}
    void operator*=(const T& scalar){Mult(scalar);}
    
    vec3<T> operator/(const T& scalar)const{return Quot(scalar);}
    void operator/=(const T& scalar){Div(scalar);}
    
    bool operator==(const vec3<T>& other)const{return Equals(other);}
    bool operator!=(const vec3<T>& other)const{return !Equals(other);}

    friend std::ostream& operator<<(std::ostream& o,const vec3<T>& v)
    {o<<"("<<v.x<<", "<<v.y<<", "<<v.z<<")";return o;}
	
	explicit operator vec2<T>() const {return vec2<T>(this->x, this->y);}
	explicit operator vec4<T>() const {return vec4<T>(this->x, this->y, this->z);}


    template<class O> operator vec3<O>() const {return vec3<O>((O)this->x, (O)this->y, (O)this->z);}
};

template<typename T> class vec4
{
public:
    union
	{
	struct {T x, y, z, w;};
    struct {T r, g, b, a;};
	T array[4];
    };
	
    vec4(const T& x = (T)0.0f, const T& y = (T)0.0f, const T& z = (T)0.0f, const T& w = (T)0.0f):x(x), y(y), z(z), w(w){}
	vec4(const vec4<T>& other):x(other.x),y(other.y),z(other.z),w(other.w){}
    vec4(const T(&array)[4]):x(array[0]),y(array[1]),z(array[2]),w(array[3]){}
    vec4(const vec2<T>& front, const T& z, const T& w):x(front.x), y(front.y), z(z), w(w){}
    vec4(const T& x, const vec2<T>& middle, const T& w):x(x), y(middle.x), z(middle.y), w(w){}
    vec4(const T& x, const T& y, const vec2<T>& back):x(x), y(y), z(back.x), w(back.y){}
    vec4(const vec2<T>& front, const vec2<T>& back):x(front.x), y(front.y), z(back.x), w(back.y){}
    vec4(const vec3<T>& front, const T& w):x(front.x), y(front.y), z(front.z), w(w){}
    vec4(const T& x, const vec3<T>& back):x(x), y(back.x), z(back.y), w(back.z){}

    vec4<T> Sum(const vec4<T>& other)const{return vec4<T>(x+other.x, y+other.y, z+other.z, w+other.w);}
    void Add(const vec4<T>& other){*this = this->Sum(other);}

    vec4<T> Dif(const vec4<T>& other)const{return vec4<T>(x-other.x, y-other.y, z-other.z, w-other.w);}
    void Sub(const vec4<T>& other){*this = this->Dif(other);}

    vec4<T> Prod(const T& scalar)const{return vec4<T>(x*scalar, y*scalar, z*scalar, w*scalar);}
    void Mult(const T& scalar){*this = this->Prod(scalar);}

    vec4<T> Quot(const T& scalar)const{return vec4<T>(x/scalar, y/scalar, z/scalar, w*scalar);}
    void Div(const T& scalar){*this = this->Quot(scalar);}

    float Dot(const vec4<T>& other)const{return (x*other.x)+(y*other.y)+(z*other.z)+(w*other.w);}
    bool Equals(const vec4<T>& other)const{return ((x==other.x) && (y==other.y) && (z==other.z) && (w==other.w));}

    //operator overloading
    void operator=(const vec4<T>& other){x = other.x; y = other.y; z = other.z; w = other.w;}

    vec4<T> operator+(const vec4<T>& other)const{return Sum(other);}
    void operator+=(const vec4<T>& other){Add(other);}
    
    vec4<T> operator-(const vec4<T>& other)const{return Dif(other);}
    void operator-=(const vec4<T>& other){Sub(other);}

    vec4<T> operator*(const T& scalar)const{return Prod(scalar);}
    void operator*=(const T& scalar){Mult(scalar);}

    vec4<T> operator/(const T& scalar)const{return Quot(scalar);}
    void operator/=(const T& scalar){Div(scalar);}

    bool operator==(const vec4<T>& other)const{return Equals(other);}
    bool operator!=(const vec4<T>& other)const{return !Equals(other);}

    friend std::ostream& operator<<(std::ostream& o,const vec4<T>& v)
	{o<<"("<<v.x<<", "<<v.y<<", "<<v.z<<", "<<v.w<<")";return o;}

	explicit operator vec2<T>() const {return vec2<T>(this->x, this->y);}
	explicit operator vec3<T>() const {return vec3<T>(this->x, this->y, this->z);}

    template<class O> operator vec4<O>() const {return vec4<O>((O)this->x, (O)this->y, (O)this->z, (O)this->w);}
};

}
#endif // GLEWY_VEC_HPP