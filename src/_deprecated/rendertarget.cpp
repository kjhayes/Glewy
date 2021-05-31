/*
#include<Glewy/rendertarget.hpp>

namespace gly
{

RenderTarget::RenderTarget(GLFWwindow* win):aspect_ratio(1.5f){window = win;SetFullWindowSize();}

void RenderTarget::SetFullWindowSize()
{
    int width, height;        
    glfwGetFramebufferSize(window, &width, &height);    
    
    float window_ar = (float)width/(float)height;
    
    int x_offset = 0, y_offset = 0;
    
    if(window_ar > aspect_ratio)
    {
        int new_width = height*aspect_ratio;
        x_offset = (width-new_width)*0.5f;
        width = new_width;
    }
    else
    {
        int new_height = width/aspect_ratio;
        y_offset = (height-new_height)*0.5f;
        height = new_height;
    }
    
    bl.x = (float)x_offset;
    bl.y = (float)y_offset;

    tr.x = (float)width;
    tr.y = (float)height;
    }

void RenderTarget::SetViewport()const
{
    glViewport(bl.x, bl.y, tr.x, tr.y);
}

}
*/