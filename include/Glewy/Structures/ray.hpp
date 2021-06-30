#ifndef GLEWY_RAY_HPP
#define GLEWY_RAY_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

//Basic Ray Interface
template<class T>
struct Ray{
public:
    virtual void SetOrigin(const vec2<T>&) = 0;
    virtual void SetOriginX(const T&) = 0;
    virtual void SetOriginY(const T&) = 0;
    virtual vec2<T> GetOrigin() const = 0;

    virtual void SetDirection(const vec2<T>&) = 0;
    virtual void SetDirectionX(const T&) = 0;
    virtual void SetDirectionY(const T&) = 0;
    virtual vec2<T> GetDirection() const = 0;

    virtual void SetTip(const vec2<T>&) = 0;
    virtual void SetTipX(const T&) = 0;
    virtual void SetTipY(const T&) = 0;
    virtual vec2<T> GetTip() const = 0;

    virtual void SetMagnitude(const gly_float&) = 0;
    virtual gly_float GetMagnitude() const = 0;

    virtual vec2<T> Normalized() const = 0;
};

//Change Direction Often, Get Magnitude Rarely
template<class T>
struct BasicRay : public Ray<T>{
protected:
    vec2<T> origin;
    vec2<T> dir;
public:
    BasicRay():origin(0,0),dir(0,0){}
    BasicRay(const vec2<T>& origin):origin(origin),dir(0,0){}
    BasicRay(const vec2<T>& origin, const vec2<T>& dir):origin(origin),dir(dir){}
    BasicRay(const BasicRay<T>& r):origin(r.origin),dir(r.dir){}

    virtual void SetOrigin(const vec2<T>& o) override {origin = o;}
    virtual void SetOriginX(const T& x) override {origin.x = x;}
    virtual void SetOriginY(const T& y) override {origin.y = y;}
    virtual vec2<T> GetOrigin() const override {return origin;}

    virtual void SetDirection(const vec2<T>& d) override {dir = d;}
    virtual void SetDirectionX(const T& x) override {dir.x = x;}
    virtual void SetDirectionY(const T& y) override {dir.y = y;}
    virtual vec2<T> GetDirection() const override {return dir;}

    virtual void SetTip(const vec2<T>& t) override {SetDirection(t-origin);}
    virtual void SetTipX(const T& x) override {SetDirectionX(x-origin.x);}
    virtual void SetTipY(const T& y) override {SetDirectionX(y-origin.y);}
    virtual vec2<T> GetTip() const override {return origin+dir;}

    virtual void SetMagnitude(const gly_float& m) override {dir = Normalized()*m;}
    virtual gly_float GetMagnitude() const override {return dir.Magnitude();}

    virtual vec2<T> Normalized() const override {return dir / GetMagnitude();}
};

//Change Direction Rarely, Get Magnitude Often
template<class T>
struct BasicMagRay : public BasicRay<T> {
protected:
    gly_float magnitude;
    virtual void CalculateMagnitude(){magnitude = BasicRay<T>::dir.Magnitude();}
public:
    BasicMagRay():BasicRay<T>(),magnitude(0.0f){}
    BasicMagRay(const vec2<T>& origin):BasicRay<T>(origin),magnitude(0.0f){}
    BasicMagRay(const vec2<T>& origin, const vec2<T>& dir):BasicRay<T>(origin,dir){CalculateMagnitude();}
    BasicMagRay(const BasicRay<T>& r):BasicRay<T>(r){CalculateMagnitude();}
    BasicMagRay(const BasicMagRay<T>& r):BasicRay<T>(r.origin, r.dir),magnitude(r.magnitude){}

    virtual void SetDirection(const vec2<T>& d) override {if(BasicRay<T>::dir!=d){BasicRay<T>::dir = d; CalculateMagnitude();}}
    virtual void SetDirectionX(const T& x) override {if(BasicRay<T>::dir.x!=x){BasicRay<T>::dir.x=x; CalculateMagnitude();}}
    virtual void SetDirectionY(const T& y) override {if(BasicRay<T>::dir.y!=y){BasicRay<T>::dir.y=y; CalculateMagnitude();}}

    virtual gly_float GetMagnitude() const override {return magnitude;}
};

}

#endif