#include<Glewy/Core/abstraction.hpp>

#include<SML/sml.hpp>
#include<Glewy/External/GLFW.h>

#include<iostream>

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
	
	sml::vec2 PixelCoordToViewPort(GLFWwindow* window, sml::vec2 pix)
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
	
	sml::vec2 ViewPortToPixelCoord(GLFWwindow* window, sml::vec2 vp)
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