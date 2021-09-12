#include<Glewy/Scene/camera.hpp>

#include<substd/mat.hpp>

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

void Camera::SetAspectRatio(const float& ar){aspect_ratio = ar; SetLocalScale(GetLocalScale());}
float Camera::GetAspectRatio(){return aspect_ratio;}

void Camera::SetSize(const gly_float& s){
    SetLocalScale({s,s,1.0f});
}

void Camera::SetLocalPosition(const ss::vec3<gly_float>& pos) {
    Transform::SetLocalPosition(pos * -1.0f);
}

void Camera::SetLocalPositionX(const gly_float& x){
    Transform::SetLocalPositionX(x*-1.0f);
}
void Camera::SetLocalPositionY(const gly_float& y){
    Transform::SetLocalPositionY(y*-1.0f);
}
void Camera::SetLocalPositionZ(const gly_float& z){
    Transform::SetLocalPositionZ(z*-1.0f);
}

void Camera::SetLocalScale(const ss::vec3<gly_float>& scal) {
    Transform::SetLocalScale({2.0f/(scal.x*aspect_ratio),2.0f/scal.y,2.0f/scal.z});
}

void Camera::SetLocalScaleX(const gly_float& x){
    Transform::SetLocalScaleX(2.0f/(x*aspect_ratio));
}
void Camera::SetLocalScaleY(const gly_float& y){
    Transform::SetLocalScaleY(2.0f/y);
}
void Camera::SetLocalScaleZ(const gly_float& z){
    Transform::SetLocalScaleZ(2.0f/z);
}

void Camera::SetLocalRotation(const ss::vec3<ss::modulo_tau<gly_float>>& rot) {
    Transform::SetLocalRotation(rot * -1.0f);
}

void Camera::SetLocalRotationX(const ss::modulo_tau<gly_float>& x){
    Transform::SetLocalRotationX(x*-1.0f);
}
void Camera::SetLocalRotationY(const ss::modulo_tau<gly_float>& y){
    Transform::SetLocalRotationY(y*-1.0f);
}
void Camera::SetLocalRotationZ(const ss::modulo_tau<gly_float>& z){
    Transform::SetLocalRotationZ(z*-1.0f);
}

ss::vec3<gly_float> Camera::GetLocalPosition() const {
    return local_position * -1.0f;
}    
ss::vec3<gly_float> Camera::GetLocalScale() const {
    return {2.0f/(Transform::local_scale.x*aspect_ratio),2.0f/Transform::local_scale.y,1.0f};
}
ss::vec3<ss::modulo_tau<gly_float>> Camera::GetLocalRotation() const {
    return local_rotation * -1.0f;
}

void Camera::CalculateLocalAABBMatrix() const {
    localAABBMatrix.Identity();

    localAABBMatrix.t = ss::vec4<gly_float>(local_position.x*local_scale.x,local_position.y*local_scale.y,local_position.z*local_scale.z, 1.0f);

    localAABBMatrix.i.x = local_scale.x;
    localAABBMatrix.j.y = local_scale.y;
    localAABBMatrix.k.z = local_scale.z;
}

}