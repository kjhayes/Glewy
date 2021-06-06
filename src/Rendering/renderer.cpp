#include<Glewy/Rendering/renderer.hpp>

#include<iostream>

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<Glewy/Core/logging.hpp>
#include<Glewy/Structures/vec.hpp>
#include<Glewy/Rendering/material.hpp>

namespace gly{

vec3<gly_float> fullscreen_vertices[4]
{
    {-1.0f,-1.0f,0.0f},
	{1.0f,-1.0f,0.0f},
	{-1.0f,1.0f,0.0f},
	{1.0f,1.0f,0.0f}
};

GLuint Renderer::full_viewport_vbo = 0;

Renderer::Renderer(const vec2<gly_int>& size)
{
    if(full_viewport_vbo == 0){
        glGenBuffers(1, &full_viewport_vbo);

        glBindBuffer(GL_ARRAY_BUFFER, full_viewport_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fullscreen_vertices), fullscreen_vertices, GL_STATIC_DRAW);
    }
    glGenFramebuffers(1, &FBO);
    glGenTextures(1, &texture);
    glGenRenderbuffers(1, &rbo);
    RegenFBO(size);
    final_pass = new Material(false);
    final_pass->SetVert_Data(
        "#version 330\n"
        "layout (location = 0) in vec3 Position;\n"
        "out vec2 TextureCoord;\n"
        "void main()\n"
        "{\n"
        "TextureCoord = (Position.xy*0.5)+vec2(0.5,0.5);\n"
        "gl_Position = vec4(Position, 1.0);\n"
        "}\n"
    );
    final_pass->SetFrag_Data( 
        "#version 330\n"   
        "in vec2 TextureCoord;\n"
        "out vec4 _color;\n"
        "uniform sampler2D gly_texture;\n"
        "void main()\n"
        "{\n"
        "vec4 color = vec4(texture(gly_texture, TextureCoord).rgb, 1.0);\n"
        "_color = color;\n" //It seems important to pass the texture value in two steps: Not Sure Why
        "}\n"
    );
    final_pass->Link();
}

Renderer::~Renderer()
{
    glDeleteFramebuffers(1, &FBO);
    glDeleteTextures(1, &texture);
    glDeleteRenderbuffers(1, &rbo);
    delete final_pass;
}

void Renderer::RegenFBO(const vec2<gly_int>& n_size){
    //Bind Framebuffer
    this->size = n_size;

    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, FBO);
    
    //Create, Bind, Format and Unbind Texture For Color Buffer
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, size.x, size.y, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    //Attach Texture to ColorAttachment0
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
    
    GLenum draw_buffers[] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, draw_buffers);

    //Renderbuffer for depth and stencil
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, size.x, size.y);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
    
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {std::cout<<"ERROR: FRAMEBUFFER IS NOT COMPLETE"<<std::endl;}
    
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Renderer::SetActive(){
    glViewport(0,0,size.x,size.y);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

void Renderer::Clear(){
    glClearColor(clear_color.r,clear_color.g,clear_color.b,clear_color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Blit(){
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDisable(GL_DEPTH_TEST);
    RenderFullscreenTexture(texture);
}

void Renderer::RenderFullscreenTexture(GLuint texture){
    final_pass->SetActive();
    GLuint gly_texture_location = glGetUniformLocation(final_pass->program, "gly_texture");
    if(gly_texture_location!=-1){glUniform1i(gly_texture_location, 0);}
    

	glBindBuffer(GL_ARRAY_BUFFER, full_viewport_vbo);

    glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glDisableVertexAttribArray(0);
}

void Renderer::SetClearColor(const vec4<gly_float>& cc){
    this->clear_color = cc;
}
vec4<gly_float> Renderer::GetClearColor(){return clear_color;}

void Renderer::SetFrag(const char* path){
    this->final_pass->SetFrag(path);
    this->final_pass->Link();
}
void Renderer::SetFrag_Data(const char* data){
    this->final_pass->SetFrag_Data(data);
    this->final_pass->Link();
}


}