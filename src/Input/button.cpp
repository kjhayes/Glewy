#include<Glewy/Input/button.hpp>

#include<Glewy/Core/instance.hpp>
#include<GLFW/glfw3.h>

namespace gly{

Button::Button(Instance* i):Inputable(i){}

void Button::Update(){
    active.Set(glfwGetKey(instance->GetWindow(), keycode));
}

}