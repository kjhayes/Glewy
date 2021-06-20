#include<Glewy/Core/instance.hpp>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include<SoLoud/soloud.h>

#include<Glewy/Core/logging.hpp>
#include<Glewy/Core/typedef.hpp>
#include<Glewy/Core/abstraction.hpp>
#include<Glewy/Core/updateinfo.hpp>
#include<Glewy/Core/root.hpp>
#include<Glewy/Scene/camera.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/renderer.hpp>
#include<Glewy/Rendering/rendercalls.hpp>

namespace gly
{
Instance::Instance(const StartUp& start):
	    last_time(0.0f),
	    curr_time(0.0f),
	    delta_time(0.0f),
		custom_aspect_ratio(1.0f),
		ar_option(GLY_USE_WINDOW_AR),
		win_size(start.size),
		title(start.title)
{
	registry.push_back(this);
	window = glewyCreateWindow(win_size.x, win_size.y, title.c_str());

	audio_engine = new SoLoud::Soloud();
	((SoLoud::Soloud*)audio_engine)->init();

	mouse = new Mouse(this);
}

Instance::~Instance(){
	registry.remove(this);
	glfwDestroyWindow(window);

	((SoLoud::Soloud*)audio_engine)->deinit();
	delete (SoLoud::Soloud*)audio_engine;

	delete mouse;
}

void Instance::Run()
{
	glfwSetWindowSizeCallback(window, OnWindowResize);

	RenderCalls::Init();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSetTime(0.0);

	UpdateViewport();

	while(!glfwWindowShouldClose(window))
	{	
		TickTime();

		UpdateAllInputs();

		current_root->UpdateEntities({delta_time, this});

		current_root->RenderWith(current_renderer);
		
		glViewport(vp_offset.x, vp_offset.y, vp_size.x, vp_size.y);
		current_renderer->Blit(clear_color);
		
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
	current_root->is_current_root_of = nullptr;
	root->is_current_root_of = this;
	UpdateViewport();
}

Renderer* Instance::GetCurrentRenderer(){return current_renderer;}
void Instance::SetCurrentRenderer(Renderer* renderer){
	current_renderer = renderer;
}

vec4<gly_float> Instance::GetClearColor(){return clear_color;}
void Instance::SetClearColor(const vec4<gly_float>& cc){clear_color = cc;}

void Instance::Get_Window_Size(int* x_out, int* y_out){glfwGetWindowSize(window, x_out, y_out);}
void Instance::Get_Buffer_Size(int* x_out, int* y_out){glfwGetFramebufferSize(window, x_out, y_out);}
void Instance::Set_Window_Size(const int& x, const int& y){glfwSetWindowSize(window, x, y);win_size.x = x; win_size.y = y;}

void Instance::Set_AR_Option(const ASPECT_RATIO_OPTION& opt){
	ar_option = opt;
	UpdateViewport();
}

GLFWwindow* Instance::GetWindow(){return window;}

void Instance::UpdateAllInputs(){
	for(auto iter = Inputable::registry.begin(); iter != Inputable::registry.end(); iter++){
		(*iter)->Update();
	}
}
Mouse* Instance::GetMouse(){return mouse;}

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
			vp_offset.x = 0;
			vp_offset.y = 0;
			vp_size.x = vec.x;
			vp_size.y = vec.y;
			return;
		case GLY_USE_ROOT_AR:
			ar = current_root->camera->GetAspectRatio();
			break;
		case GLY_USE_CUSTOM_AR:
			ar = custom_aspect_ratio;
			break;
	}
	if(window_ar > ar){
		//Match Y's
		vp_size.x = vec.y * ar;
		vp_size.y = vec.y;
		vp_offset.x = (vec.x-vp_size.x)*0.5f;
		vp_offset.y = 0;
	}
	else{
		//Match X's
		vp_size.x = vec.x;
		vp_size.y = vec.x / ar;
		vp_offset.x = 0;
		vp_offset.y = (vec.y-vp_size.y)*0.5f;
	}
}

void Instance::OnWindowResize(GLFWwindow* window, int x, int y){
	Instance* i = GetInstanceFromWindow(window);
	if(i!=nullptr){i->OnOwnWindowResize({x,y});}
}	

void Instance::OnOwnWindowResize(const vec2<gly_int>& size){
	win_size = size;
	UpdateViewport(size);
}

Instance* Instance::GetInstanceFromWindow(GLFWwindow* window){
	for(auto iter = registry.begin(); iter != registry.end(); iter++){
		if((*iter)->window == window){return (*iter);}
	}	
	return nullptr;
}

void* Instance::GetAudioEngine(){return audio_engine;}

}