#ifndef GLEWY_RENDERER_HPP
#define GLEWY_RENDERER_HPP

#include<Glewy/Structures/vec.hpp>

typedef unsigned int GLuint;

namespace gly{

class Material;

class Renderer{
private:
    static GLuint full_viewport_vbo;

    vec2<gly_int> size;

    GLuint FBO;
    GLuint texture;
    GLuint rbo;

    Material* final_pass;

    vec4<gly_float> clear_color;

public:
    Renderer(const vec2<gly_int>&);
    ~Renderer();

    void RegenFBO(const vec2<gly_int>&);
    
    void SetActive();
    void Clear(const vec4<gly_float>& color);
    
    void Blit(const vec4<gly_float>& clear);
    void RenderFullscreenTexture(GLuint texture);

    void SetClearColor(const vec4<gly_float>&);
    vec4<gly_float> GetClearColor();

    void SetFrag(const char*);
    void SetFrag_Data(const char*);
};

}

#endif //GLEWY_RENDERER_HPP