#include<Glewy/Core/instance.hpp>

#include<Glewy/Core/logging.hpp>

#include<Glewy/External/GLFW.h>
#include<Glewy/Core/abstraction.hpp>
#include<Glewy/Scene/root.hpp>
#include<Glewy/Core/updateinfo.hpp>
#include<Glewy/Rendering/material.hpp>

namespace gly
{

Instance::Instance(const StartUp& start):
	    last_time(0.0f),
	    curr_time(0.0f),
	    delta_time(0.0f)
{
    window = glewyCreateWindow(start.x_size, start.y_size, start.title);
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

void Instance::TickTime()
{
	curr_time = glfwGetTime();
	delta_time = curr_time - last_time;
	last_time = curr_time;
}

}