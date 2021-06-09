#include<Glewy/Structures/inversetransform.hpp>

namespace gly{

InverseTransform::InverseTransform():Transform(){}
InverseTransform::InverseTransform(Transform* parent):Transform(parent){}

void InverseTransform::SetPosition(const vec3<gly_float>& pos) {
    Transform::SetPosition(pos * -1.0f);
}
void InverseTransform::SetScale(const vec3<gly_float>& scal) {
    Transform::SetScale({1.0f/scal.x,1.0f/scal.y,1.0f/scal.z});
}
void InverseTransform::SetRotation(const vec3<modulo_tau<gly_float>>& rot) {
    Transform::SetRotation(rot * -1.0f);
}

vec3<gly_float> InverseTransform::GetPosition() const {
    return position * -1.0f;
}    
vec3<gly_float> InverseTransform::GetScale() const {
    return {1.0f/scale.x,1.0f/scale.y,1.0f/scale.z};
}
vec3<modulo_tau<gly_float>> InverseTransform::GetRotation() const {
    return rotation * -1.0f;
}


}