#include<Glewy/deprecated/transform.hpp>

namespace gly
{
	
Transform::Transform():position(0.0f,0.0f,0.0f),scale(1.0f,1.0f,1.0f){UpdateMatrix();}

void Transform::UpdateMatrix() 
{
	matrix.t.x = position.x;
	matrix.t.y = position.y;
	matrix.t.z = position.z;
	
	matrix.i.x = scale.x;
	matrix.j.y = scale.y;
	matrix.k.z = scale.z;
}

sml::mat4 Transform::Matrix()
{
	UpdateMatrix();
	return matrix;	
}
	
}