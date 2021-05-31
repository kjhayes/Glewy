/*
#include<Glewy/camera.hpp>
namespace gly
{

Camera::Camera(Entity* parent):Entity(parent),aspect_ratio(1.3333f){SetSize(1.0f);}
Camera::Camera(Entity* parent, const float& size):Entity(parent),aspect_ratio(1.3333f){SetSize(size);}

void Camera::UpdateCameraMatrix()
{
    cam_matrix.t.x = -position.x;
	cam_matrix.t.y = -position.y;
	cam_matrix.t.z = -position.z;
	
	cam_matrix.i.x = size_reciprocal/aspect_ratio;
	cam_matrix.j.y = size_reciprocal;
	cam_matrix.k.z = 1.0f;
}

sml::mat4 Camera::CameraMatrix()
{
    UpdateCameraMatrix();
    return cam_matrix;
}


float Camera::GetSize() const {return 2.0f/(size_reciprocal);}
void Camera::SetSize(const float& size){size_reciprocal = 2.0f/(size);}

}
*/