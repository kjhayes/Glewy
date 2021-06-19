#include<Glewy/Scene/camera.hpp>

#include<Glewy/Structures/mat.hpp>

#include<cmath>

namespace gly
{

Camera::Camera():Transform(),aspect_ratio(1.0f)
{
    SetSize(1.0f);
}
Camera::Camera(Transform* parent):Transform(parent),aspect_ratio(1.0f){
    SetSize(1.0f);
}

void Camera::SetAspectRatio(const float& ar){aspect_ratio = ar; CalculateScale();}
float Camera::GetAspectRatio(){return aspect_ratio;}

void Camera::SetSize(const float& size){
    this->size = size;
    CalculateScale();
}
float Camera::GetSize(){return size;}

void Camera::CalculateScale(){
    float d_size = 0.5f*size;
    SetScale({d_size*aspect_ratio,d_size,1.0f});
}

void Camera::SetPosition(const vec3<gly_float>& pos) {
    Transform::SetPosition(pos * -1.0f);
}
void Camera::SetScale(const vec3<gly_float>& scal) {
    Transform::SetScale({1.0f/scal.x,1.0f/scal.y,1.0f/scal.z});
}
void Camera::SetRotation(const vec3<modulo_tau<gly_float>>& rot) {
    Transform::SetRotation(rot * -1.0f);
}

vec3<gly_float> Camera::GetPosition() const {
    return position * -1.0f;
}    
vec3<gly_float> Camera::GetScale() const {
    return {1.0f/scale.x,1.0f/scale.y,1.0f/scale.z};
}
vec3<modulo_tau<gly_float>> Camera::GetRotation() const {
    return rotation * -1.0f;
}

void Camera::CalculateAABBMatrix() {
    aabbMatrix.Identity();

    aabbMatrix.t = vec4<gly_float>(position.x*scale.x,position.y*scale.y,position.z*scale.z, 1.0f);

    aabbMatrix.i.x = scale.x;
    aabbMatrix.j.y = scale.y;
    aabbMatrix.k.z = scale.z;
}

}