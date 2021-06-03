#include<Glewy/Core/instance.hpp>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include<Glewy/Core/abstraction.hpp>
#include<Glewy/Core/updateinfo.hpp>
#include<Glewy/Scene/root.hpp>
#include<Glewy/Scene/camera.hpp>
#include<Glewy/Rendering/material.hpp>

namespace gly
{
std::list<Instance*> Instance::registry;

Instance::Instance(const StartUp& start):
	    last_time(0.0f),
	    curr_time(0.0f),
	    delta_time(0.0f),
		custom_aspect_ratio(1.0f),
		ar_option(GLY_USE_WINDOW_AR)
{
	registry.push_back(this);
    window = glewyCreateWindow(start.x_size, start.y_size, start.title);
	glfwSetWindowSizeCallback(window, OnWindowResize);
}

Instance::~Instance(){
	registry.remove(this);
	glfwDestroyWindow(window);
}

void Instance::Run()
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSetTime(0.0);
	
	while(!glfwWindowShouldClose(window))
	{	
		TickTime();

		current_root->UpdateEntities({delta_time, this});

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		Material::RenderAll(current_root->camera);
		
		glfwSwapBuffers(window);
		
		glfwPollEvents();
	}
    glfwTerminate();
}

void Instance::TickTime(){
	curr_time = glfwGetTime();
	delta_time = curr_time - last_time;
	last_time = curr_time;
}

Root* Instance::GetCurrentRoot(){return current_root;}
void Instance::SetCurrentRoot(Root* root){
	current_root = root;
}

void Instance::Get_Window_Size(int* x_out, int* y_out){glfwGetWindowSize(window, x_out, y_out);}
void Instance::Get_Buffer_Size(int* x_out, int* y_out){glfwGetFramebufferSize(window, x_out, y_out);}
void Instance::Set_Window_Size(const int& x, const int& y){glfwSetWindowSize(window, x, y);}

void Instance::Set_AR_Option(const ASPECT_RATIO_OPTION& opt){
	ar_option = opt;
	UpdateViewport();
}

GLFWwindow* Instance::GetWindow(){return window;}

void Instance::SetClearColor(const vec4<char>& color){
	clear_color = color;
	constexpr float rec255 = 1/255;
	glClearColor(color.r*rec255, color.g*rec255, color.b*rec255, color.a*rec255);
}
vec4<char> Instance::GetClearColor(){
	return clear_color;
}

void Instance::UpdateViewport(){
	int x, y;
	glfwGetWindowSize(window, &x, &y);
	UpdateViewport({x, y});
}
void Instance::UpdateViewport(const vec2<gly_int>& vec){
	float window_ar = ((float)vec.x)/((float)vec.y);
	//AR Close to Zero = Tall; Close to Infinity = Wide;
	float ar;
	switch(ar_option){
		case GLY_USE_WINDOW_AR:
			glViewport(0,0,vec.x,vec.y);
			return;
		case GLY_USE_ROOT_AR:
			ar = current_root->camera->GetAspectRatio();
			break;
		case GLY_USE_CUSTOM_AR:
			ar = custom_aspect_ratio;
			break;
	}
	int offset_x, offset_y, nx, ny;
	if(window_ar > ar){
		//Match Y's
		nx = vec.y * ar;
		ny = vec.y;
		offset_x = (vec.x-nx)*0.5f;
		offset_y = 0;
	}
	else{
		//Match X's
		nx = vec.x;
		ny = vec.x / ar;
		offset_x = 0;
		offset_y = (vec.y-ny)*0.5f;
	}
	glViewport(offset_x, offset_y, nx, ny);
}

void Instance::OnWindowResize(GLFWwindow* window, int x, int y){
	for(auto iter = registry.begin(); iter != registry.end(); iter++){
		(*iter)->UpdateViewport({x, y});
	}
}	

}