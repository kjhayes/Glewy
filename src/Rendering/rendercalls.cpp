#include<Glewy/Rendering/rendercalls.hpp>

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<substd/transform.hpp>
#include<Glewy/Rendering/texture.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Core/logging.hpp>

namespace gly{

static GLuint quad_VBO;
static GLuint offset_VBO;

void RenderCalls::Init(){
	//QUAD
	glGenBuffers(1, &quad_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, quad_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices_default), quad_vertices_default, GL_STATIC_DRAW);	
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &offset_VBO);
}


const ss::vec3<gly_float> RenderCalls::quad_vertices_default[4] = 
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

void RenderCalls::RenderQuads2i(ss::vec2<gly_int>* offsets, const unsigned int& number)
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, quad_VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, offset_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ss::vec2<gly_int>) * number, offsets, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 2, GL_INT, GL_FALSE, 2 * sizeof(gly_int), (void*)0);

	glVertexAttribDivisor(1, 1);
		
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, number);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
/*
void RenderCalls::RenderQuads2f(vec2<gly_float>* offsets, const unsigned int& number){
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);		
	glBindBuffer(GL_ARRAY_BUFFER, quad_VBO);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(gly_float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, offset_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec2<gly_float>) * number, offsets, GL_DYNAMIC_DRAW);
	
	glVertexAttribDivisor(1, 1);  
	
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, number);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
void RenderCalls::RenderQuads3i(vec3<gly_int>* offsets, const unsigned int& number){
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);		
	glBindBuffer(GL_ARRAY_BUFFER, quad_VBO);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_INT, GL_FALSE, 3 * sizeof(gly_int), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, offset_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3<gly_int>) * number, &offsets[0], GL_STATIC_DRAW);
	glVertexAttribDivisor(1, 1);  
	
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, number);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
void RenderCalls::RenderQuads3f(vec3<gly_float>* offsets, const unsigned int& number){

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, quad_VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);		
	
	
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, offset_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vec3<gly_float>) * number, &offsets[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(gly_float), (void*)0);
	
	glVertexAttribDivisor(1, 1);  
	
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, number);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
*/

void RenderCalls::RenderLine(){
	glLineWidth(10.0f);
	glDrawArrays(GL_LINES, 0, 2);
}
void RenderCalls::RenderLine(const gly_float& f){
	glLineWidth(f);
	glDrawArrays(GL_LINES, 0, 2);
}

}