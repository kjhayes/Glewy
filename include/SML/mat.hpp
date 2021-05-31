#ifndef SML_MAT_HPP
#define SML_MAT_HPP
#include<SML/vec.hpp>

namespace sml
{
class mat2
{
public:
    vec2 i, j;
    mat2();
    mat2(vec2, vec2);

    vec2 RowX()const;
    vec2 RowY()const;

    vec2 VecMult(const vec2&)const;
    mat2 MatMult(const mat2&)const;

    vec2 operator*(const vec2&)const;
    mat2 operator*(const mat2&)const;

    void Identity();
};

class mat3
{
public:
    vec3 i, j, k;
    mat3();
    mat3(vec3, vec3, vec3);

    vec3 RowX()const;
    vec3 RowY()const;
    vec3 RowZ()const;

    vec3 VecMult(const vec3&)const;
    mat3 MatMult(const mat3&)const;

    vec3 operator*(const vec3&)const;
    mat3 operator*(const mat3&)const;

    void Identity();
};

class mat4
{
public:
    vec4 i, j, k, t;
    mat4();
    mat4(vec4, vec4, vec4, vec4);

    vec4 RowX()const;
    vec4 RowY()const;
    vec4 RowZ()const;
    vec4 RowW()const;

    vec4 VecMult(const vec4&)const;
    mat4 MatMult(const mat4&)const;

    vec4 operator*(const vec4&)const;
    mat4 operator*(const mat4&)const;

    void Identity();
    void PerspectiveProjection(const vec2&, const float&, const float&, const float&);
};
}
#endif // SML_MAT_HPP
