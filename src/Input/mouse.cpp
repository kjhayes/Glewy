#include<Glewy/Input/mouse.hpp>

#include<cmath>

#include<Glewy/Core/instance.hpp>
#include<GLFW/glfw3.h>

namespace gly{

Mouse::Mouse(Instance* i):Inputable(i){}

vec2<double> Mouse::GetPosition(){return position;}
vec2<int> Mouse::GetPixelPosition(){return {floor(position.x), floor(position.y)};}
vec2<double> Mouse::GetNormalizedPosition(){
    vec2<int> v; 
    instance->Get_Window_Size(&v.x,&v.y);
    return {position.x/(double)v.x, position.y/(double)v.y};
}

void Mouse::Update() {
    glfwGetCursorPos(instance->GetWindow(), &position.x, &position.y);
}

}