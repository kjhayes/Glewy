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

void Camera::SetAspectRatio(const float& ar){aspect_ratio = ar; SetScale(GetScale());}
float Camera::GetAspectRatio(){return aspect_ratio;}

void Camera::SetSize(const gly_float& s){
    SetScale({s,s,1.0f});
}

void Camera::SetPosition(const vec3<gly_float>& pos) {
    Transform::SetPosition(pos * -1.0f);
}

void Camera::SetPositionX(const gly_float& x){
    Transform::SetPositionX(x*-1.0f);
}
void Camera::SetPositionY(const gly_float& y){
    Transform::SetPositionY(y*-1.0f);
}
void Camera::SetPositionZ(const gly_float& z){
    Transform::SetPositionZ(z*-1.0f);
}

void Camera::SetScale(const vec3<gly_float>& scal) {
    Transform::SetScale({2.0f/(scal.x*aspect_ratio),2.0f/scal.y,2.0f/scal.z});
}

void Camera::SetScaleX(const gly_float& x){
    Transform::SetScaleX(2.0f/(x*aspect_ratio));
}
void Camera::SetScaleY(const gly_float& y){
    Transform::SetScaleY(2.0f/y);
}
void Camera::SetScaleZ(const gly_float& z){
    Transform::SetScaleZ(2.0f/z);
}

void Camera::SetRotation(const vec3<modulo_tau<gly_float>>& rot) {
    Transform::SetRotation(rot * -1.0f);
}

void Camera::SetRotationX(const modulo_tau<gly_float>& x){
    Transform::SetRotationX(x*-1.0f);
}
void Camera::SetRotationY(const modulo_tau<gly_float>& y){
    Transform::SetRotationY(y*-1.0f);
}
void Camera::SetRotationZ(const modulo_tau<gly_float>& z){
    Transform::SetRotationZ(z*-1.0f);
}

vec3<gly_float> Camera::GetPosition() const {
    return position * -1.0f;
}    
vec3<gly_float> Camera::GetScale() const {
    return {2.0f/(scale.x*aspect_ratio),2.0f/scale.y,1.0f};
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