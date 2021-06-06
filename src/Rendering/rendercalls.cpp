#include<Glewy/Rendering/rendercalls.hpp>

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<Glewy/Structures/transform.hpp>
#include<Glewy/Rendering/texture.hpp>
#include<Glewy/Rendering/material.hpp>

namespace gly{

static GLuint quad_VBO;

void RenderCalls::Init(){
    //QUAD
    glGenBuffers(1, &quad_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, quad_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices_default), quad_vertices_default, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

const char* RenderCalls::transform_texture_vert_shader_default = 
    "#version 330\n"
    "layout (location = 0) in vec3 Position;\n"
    "out vec2 TextureCoord;\n"
    "uniform mat4 gly_transform;\n"
    "uniform mat4 gly_view;\n"
    "void main()\n"
    "{\n"
	"TextureCoord = Position.xy+vec2(0.5,0.5);\n"
	"gl_Position = gly_view*gly_transform*vec4(Position, 1.0);}";
    
const char* RenderCalls::transform_texture_frag_shader_default = 
    "#version 330\n"
    "in vec2 TextureCoord;\n"
    "out vec4 _color;\n"
    "uniform sampler2D gly_texture;\n"
    "void main()\n"
    "{\n"
	"_color = texture2D(gly_texture, TextureCoord);\n"
    "}\n";

const vec3<gly_float> RenderCalls::quad_vertices_default[4] = 
{
	{-0.5f,-0.5f,0.0f},
	{0.5f,-0.5f,0.0f},
	{-0.5f,0.5f,0.0f},
	{0.5f,0.5f,0.0f}
};

void RenderCalls::RenderQuad(){
    
	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, quad_VBO);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glDisableVertexAttribArray(0);

}

}