#ifndef GLEWY_RENDERER_HPP
#define GLEWY_RENDERER_HPP

#include<substd/vec.hpp>
#include<Glewy/Core/typedef.hpp>

typedef unsigned int GLuint;

namespace gly{

class Material;

class Renderer{
private:
    static GLuint full_viewport_vbo;

    ss::vec2<gly_int> size;

    GLuint FBO;
    GLuint texture;
    GLuint rbo;

    Material* final_pass;

    ss::vec4<gly_float> clear_color;

public:
    Renderer(const ss::vec2<gly_int>&);
    ~Renderer();

    void RegenFBO(const ss::vec2<gly_int>&);
    
    void SetActive();
    void Clear(const ss::vec4<gly_float>& color);
    
    void Blit(const ss::vec4<gly_float>& clear);
    void RenderFullscreenTexture(GLuint texture);

    void SetClearColor(const ss::vec4<gly_float>&);
    ss::vec4<gly_float> GetClearColor();

    void SetFrag(const char*);
    void SetFrag_Data(const char*);
};

}

#endif //GLEWY_RENDERER_HPP