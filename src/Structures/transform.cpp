#include<Glewy/Structures/transform.hpp>

#include<cmath>

namespace gly
{

Transform::Transform():Tree(nullptr), scale(1.0f,1.0f,1.0f){}
Transform::Transform(Transform* parent):Tree(parent), scale(1.0f,1.0f,1.0f){}

void Transform::CalculatePlugMatrix()
{
    plugMatrix.Identity();
    
    plugMatrix.t = sml::vec4(position, 1.0f);

    plugMatrix.i.x = scale.x;
    plugMatrix.j.y = scale.y;
    plugMatrix.k.z = scale.z;
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
        sml::mat4 yrot;
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
        sml::mat4 xrot;
        xrot.j.y = cos;
        xrot.j.z = sin;
        xrot.k.y = -sin;
        xrot.k.z = cos;
        rotationMatrix = xrot*rotationMatrix;    
    }
}

void Transform::CalculateMatrix()
{
    matrix = RotationMatrix() * PlugMatrix();
}

sml::mat4 Transform::PlugMatrix()
{
    if(plugHasChanged)
    {
        CalculatePlugMatrix();
        plugHasChanged = false;
    }
    return plugMatrix;
}

sml::mat4 Transform::RotationMatrix()
{
    if(rotationHasChanged)
    {
        CalculateRotationMatrix();
        rotationHasChanged = false;
    }
    return rotationMatrix;
}

sml::mat4 Transform::LocalMatrix()
{
    if(plugHasChanged || rotationHasChanged)
    {CalculateMatrix();}
    return matrix;
}

sml::mat4 Transform::GlobalMatrix()
{
    if(parent==nullptr)
    {
        return LocalMatrix();
    }
    return (((Transform*)parent)->GlobalMatrix()) * LocalMatrix();
}


sml::vec3 Transform::GetPosition() const
{return position;}

void Transform::SetPosition(const sml::vec3& pos)
{position = pos; plugHasChanged = true;}
        
sml::vec3 Transform::GetScale() const
{return scale;}
void Transform::SetScale(const sml::vec3& scl)
{scale = scl; plugHasChanged = true;}

sml::vec3 Transform::GetRotation() const
{return rotation;}
void Transform::SetRotation(const sml::vec3& rot)
{rotation = rot; rotationHasChanged = true;}

Transform* Transform::GetParent()
{
    return (Transform*)parent;
}

}