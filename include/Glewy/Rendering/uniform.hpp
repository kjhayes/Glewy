#ifndef GLEWY_UNIFORM_HPP
#define GLEWY_UNIFORM_HPP

#include<Glewy/Core/typedef.hpp>
#include<substd/mat.hpp>

namespace ss{
    class Transform;
}

namespace gly{

class Material;
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
    static void SetUniform(Uniform*, const ss::vec2<float>&);
    static void SetUniform(Uniform*, const ss::vec3<float>&);
    static void SetUniform(Uniform*, const ss::vec4<float>&);
    static void SetUniform(Uniform*, const int&);
    static void SetUniform(Uniform*, const ss::vec2<int>&);
    static void SetUniform(Uniform*, const ss::vec3<int>&);
    static void SetUniform(Uniform*, const ss::vec4<int>&);
    static void SetUniform(Uniform*, const unsigned int&);
    static void SetUniform(Uniform*, const ss::vec2<unsigned int>&);
    static void SetUniform(Uniform*, const ss::vec3<unsigned int>&);
    static void SetUniform(Uniform*, const ss::vec4<unsigned int>&);
    static void SetUniform(Uniform*, const ss::mat2<float>&);
    static void SetUniform(Uniform*, const ss::mat3<float>&);
    static void SetUniform(Uniform*, const ss::mat4<float>&);
    
    static void SetUniform(Uniform*, ss::Transform*);
    static void SetUniform(Uniform*, Texture*);
};

}

#endif //GLEWY_UNIFORM_HPP