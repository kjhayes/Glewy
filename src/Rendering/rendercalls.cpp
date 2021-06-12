#include<Glewy/Rendering/rendercalls.hpp>

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<Glewy/Structures/transform.hpp>
#include<Glewy/Rendering/texture.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Core/logging.hpp>

namespace gly{

static GLuint quad_VBO;

void RenderCalls::Init(){
	//QUAD
	glGenBuffers(1, &quad_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, quad_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices_default), quad_vertices_default, GL_STATIC_DRAW);	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


const vec3<gly_float> RenderCalls::quad_vertices_default[4] = 
{
	{-0.5f,-0.5f,0.0f},
	{0.5f,-0.5f,0.0f},
	{-0.5f,0.5f,0.0f},
	{0.5f,0.5f,0.0f}
};

void RenderCalls::RenderQuad(){
	
	glBindBuffer(GL_ARRAY_BUFFER, quad_VBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDisableVertexAttribArray(0);

}

}