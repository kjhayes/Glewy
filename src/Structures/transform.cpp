#include<Glewy/Structures/transform.hpp>

#include<cmath>

namespace gly
{

Transform::Transform():Tree(nullptr), scale(1.0f,1.0f,1.0f){}
Transform::Transform(Transform* parent):Tree(parent), scale(1.0f,1.0f,1.0f){}

void Transform::CalculateAABBMatrix()
{
    aabbMatrix.t = vec4<gly_float>(position, 1.0f);

    aabbMatrix.i.x = scale.x;
    aabbMatrix.j.y = scale.y;
    aabbMatrix.k.z = scale.z;
}

void Transform::CalculateRotationMatrix()
{
    rotationMatrix.Identity();
    float cos, sin;
    if(rotation.z!=0.0f)
    {
        cos = std::cos(rotation.z);
        sin = std::sin(rotation.z);
        rotationMatrix.i.x = cos;
        rotationMatrix.i.y = sin;
        rotationMatrix.j.x = -sin;
        rotationMatrix.j.y = cos;
    }
    if(rotation.y!=0.0f)
    {
        cos = std::cos(rotation.y);
        sin = std::sin(rotation.y);
        mat4<gly_float> yrot;
        yrot.i.x = cos;
        yrot.i.z = -sin;
        yrot.k.x = sin;
        yrot.k.z = cos;
        rotationMatrix = yrot*rotationMatrix;
    }
    if(rotation.x!=0.0f)
    {
        cos = std::cos(rotation.x);
        sin = std::sin(rotation.x);
        mat4<gly_float> xrot;
        xrot.j.y = cos;
        xrot.j.z = sin;
        xrot.k.y = -sin;
        xrot.k.z = cos;
        rotationMatrix = xrot*rotationMatrix;    
    }
}

void Transform::CalculateMatrix()
{
    local_matrix = AABBMatrix() * RotationMatrix();
}

mat4<gly_float> Transform::AABBMatrix()
{
    if(AABBHasChanged)
    {
        CalculateAABBMatrix();
        AABBHasChanged = false;
    }
    return aabbMatrix;
}

mat4<gly_float> Transform::RotationMatrix()
{
    if(rotationHasChanged)
    {
        CalculateRotationMatrix();
        rotationHasChanged = false;
    }
    return rotationMatrix;
}

mat4<gly_float> Transform::LocalMatrix()
{
    if(AABBHasChanged || rotationHasChanged)
    {CalculateMatrix();}
    return local_matrix;
}

mat4<gly_float> Transform::GlobalMatrix()
{
    if(parent != nullptr){
        if(parentHasChanged){
            Transform* p = ((Transform*)parent);
            global_matrix = LocalMatrix() * p->GlobalMatrix();
            parentHasChanged = false;
            p->childrenAreNotified = false;
        }
        return global_matrix;
    }
    else{return LocalMatrix();}
}


vec3<gly_float> Transform::GetPosition() const
{return position;}
void Transform::SetPosition(const vec3<gly_float>& pos)
{if(position != pos){position = pos; AABBHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}}
        
void Transform::SetPositionX(const gly_float& x){
    if(position.x != x){position.x = x; AABBHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}
}
void Transform::SetPositionY(const gly_float& y){
    if(position.y != y){position.y = y; AABBHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}
}
void Transform::SetPositionZ(const gly_float& z){
    if(position.z != z){position.z = z; AABBHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}
}

vec3<gly_float> Transform::GetScale() const
{return scale;}
void Transform::SetScale(const vec3<gly_float>& scl)
{if(scale != scl){scale = scl; AABBHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}}

void Transform::SetScaleX(const gly_float& x){
    if(scale.x != x){scale.x = x; AABBHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}
}
void Transform::SetScaleY(const gly_float& y){
    if(scale.y != y){scale.y = y; AABBHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}
}
void Transform::SetScaleZ(const gly_float& z){
    if(scale.z != z){scale.z = z; AABBHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}
}

vec3<modulo_tau<gly_float>> Transform::GetRotation() const
{return rotation;}
void Transform::SetRotation(const vec3<modulo_tau<gly_float>>& rot)
{if(rotation != rot){rotation = rot; rotationHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}}

void Transform::SetRotationX(const modulo_tau<gly_float>& x){
    if(rotation.x != x){rotation.x = x; rotationHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}
}
void Transform::SetRotationY(const modulo_tau<gly_float>& y){
    if(rotation.y != y){rotation.y = y; rotationHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}
}
void Transform::SetRotationZ(const modulo_tau<gly_float>& z){
    if(rotation.z != z){rotation.z = z; rotationHasChanged = true; if(!childrenAreNotified){NotifyChildren();}}
}

Rect<gly_float> Transform::GetRect(){
    return Rect<gly_float>({position.x,position.y}, {scale.x,scale.y});
}
void Transform::SetRect(const Rect<gly_float>& r){
    position.x = r.center.x;
    position.y = r.center.y;
    scale.x = r.dimensions.x;
    scale.y = r.dimensions.y;
}

Transform* Transform::GetParent()
{
    return (Transform*)parent;
}

void Transform::NotifyChildren(){
    for(auto child = children.begin(); child != children.end(); child++){
        ((Transform*)(*child))->parentHasChanged = true;
    }
    childrenAreNotified = true;
}

}