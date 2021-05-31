#include<Glewy/Core/instance.hpp>

#include<Glewy/External/GLFW.h>
#include<Glewy/Core/abstraction.hpp>
#include<Glewy/Scene/root.hpp>
#include<Glewy/Scene/camera.hpp>
#include<Glewy/Core/updateinfo.hpp>
#include<Glewy/Rendering/material.hpp>

namespace gly
{
std::list<Instance*> Instance::registry;

Instance::Instance(const StartUp& start):
	    last_time(0.0f),
	    curr_time(0.0f),
	    delta_time(0.0f)
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

		current_root->UpdateEntities({delta_time});

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

void Instance::UpdateViewport(){
	int x, y;
	glfwGetWindowSize(window, &x, &y);
}
void Instance::UpdateViewport(int x, int y){
	float window_ar = ((float)x)/((float)y);
	//AR Close to Zero = Tall; Close to Infinity = Wide;
	float root_ar = current_root->camera->aspect_ratio;
	int offset_x, offset_y, nx, ny;
	if(window_ar > root_ar){
		//Match Y's
		nx = y * root_ar;
		ny = y;
		offset_x = (x-nx)*0.5f;
		offset_y = 0;
	}
	else{
		//Match X's
		nx = x;
		ny = x / root_ar;
		offset_x = 0;
		offset_y = (y-ny)*0.5f;
	}
	glViewport(offset_x, offset_y, nx, ny);
}

void Instance::OnWindowResize(GLFWwindow* window, int x, int y){
	for(auto iter = registry.begin(); iter != registry.end(); iter++){
		(*iter)->UpdateViewport(x, y);
	}
}	

}