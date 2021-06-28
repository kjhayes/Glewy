#include<Glewy/Core/abstraction.hpp>

#include<Glewy/Structures/mat.hpp>

#include<iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace gly
{
	
	GLFWwindow* glewyCreateWindow(const int& x, const int& y, const char* title)
	{
		if(!glfwInit())
		{std::cerr<<"GLFW FAILED TO INIT"<<std::endl;}
		GLFWwindow* window = glfwCreateWindow(x, y, title, NULL, NULL);
		glfwMakeContextCurrent(window);
		if(glewInit()!=GLEW_OK)
		{std::cerr<<"GLEW FAILED TO INIT"<<std::endl;}
		return window;
	}
	
	vec2<gly_float> PixelCoordToViewPort(GLFWwindow* window, vec2<gly_float> pix)
	{
		int x, y;
		glfwGetFramebufferSize(window, &x, &y);
		pix.y = y - pix.y;
		pix.x /= x;
		pix.y /= y;
		pix *= 2.0f;
		pix.x--; pix.y--;
		return pix;
	}
	
	vec2<gly_float> ViewPortToPixelCoord(GLFWwindow* window, vec2<gly_float> vp)
	{
		int x,y;
		glfwGetFramebufferSize(window, &x, &y);
		vp.x+=1.0f;vp.y+=1.0f;
		vp*=0.5f;
		vp.x*=x;
		vp.y*=y;
		vp.y = y - vp.y;
		return vp;
	}

	/*
	sml::vec2 PixelCoordToCamera(Camera* camera, sml::vec2 pix)
	{
		int x, y;
		glfwGetFramebufferSize(camera->render_target, &x, &y);
		pix.y = y - pix.y;
		pix.x /= x;
		pix.y /= y;
		pix *= 2.0f;
		pix.x--; pix.y--;
		pix.x/=camera->aspect_ratio;
		pix.x+=camera->position.x;
		pix.y+=camera->position.y;
		return pix;
	}
	*/
}