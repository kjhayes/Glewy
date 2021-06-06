#ifndef GLEWY_UNIFORM_HPP
#define GLEWY_UNIFORM_HPP

#include<Glewy/Structures/mat.hpp>

namespace gly{

class Material;
class Transform;
class Texture;

class Uniform{
private:
    const Material* material;
    int location = -1;
    
public:
    Uniform(Material*);
    Uniform(Material*, const char*);

    void SetUniformName(const char*);

    int GetLocation();

    bool Exists();

    static void SetUniform(Uniform*, const float&);
    static void SetUniform(Uniform*, const vec2<float>&);
    static void SetUniform(Uniform*, const vec3<float>&);
    static void SetUniform(Uniform*, const vec4<float>&);
    static void SetUniform(Uniform*, const int&);
    static void SetUniform(Uniform*, const vec2<int>&);
    static void SetUniform(Uniform*, const vec3<int>&);
    static void SetUniform(Uniform*, const vec4<int>&);
    static void SetUniform(Uniform*, const unsigned int&);
    static void SetUniform(Uniform*, const vec2<unsigned int>&);
    static void SetUniform(Uniform*, const vec3<unsigned int>&);
    static void SetUniform(Uniform*, const vec4<unsigned int>&);
    static void SetUniform(Uniform*, const mat2<float>&);
    static void SetUniform(Uniform*, const mat3<float>&);
    static void SetUniform(Uniform*, const mat4<float>&);
    
    static void SetUniform(Uniform*, Transform*);
    static void SetUniform(Uniform*, Texture*);
};

}

#endif //GLEWY_UNIFORM_HPP