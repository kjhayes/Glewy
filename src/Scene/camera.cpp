#include<Glewy/Scene/camera.hpp>

#include<SML/sml.hpp>
#include<Glewy/Structures/transform.hpp>

#include<cmath>

namespace gly
{

Camera::Camera():depth(10.0f),aspect_ratio(1.333f)
{SetSize(5.0f);}

sml::mat4 Camera::ViewMatrix() const
{
    sml::mat4 view;
    sml::vec4 t = transform->GlobalMatrix().t;
    view.t = t * -1.0f;
    view.t.w = 1.0f;
    view.i.x = size_reciprocal/aspect_ratio;
	view.j.y = size_reciprocal;

    view.k.z = 1.0f;
    return view;
}

void Camera::SetSize(const float& size){if(size==0.0f){size_reciprocal = 2.0f;return;}size_reciprocal = 2.0f/size;}
float Camera::GetSize(){return 2.0f/size_reciprocal;}

}