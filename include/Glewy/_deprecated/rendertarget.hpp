/*
#ifndef GLEWY_RENDER_TARGET_HPP
#define GLEWY_RENDER_TARGET_HPP

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>

namespace gly
{

class RenderTarget
{
    public:
        RenderTarget(GLFWwindow*);

        GLFWwindow* window;
        sml::vec2 bl;
        sml::vec2 tr;

        float aspect_ratio;

        void SetFullWindowSize();
        void SetViewport() const;
};

}

#endif
*/