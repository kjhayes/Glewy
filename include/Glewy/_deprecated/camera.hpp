/*
#ifndef GLEWY_CAMERA_HPP
#define GLEWY_CAMERA_HPP

#include<Glewy/entity.hpp>

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>

namespace gly
{

class Camera : public Entity
{
    private:
    using Entity::scale;
    float size_reciprocal;
    sml::mat4 cam_matrix;

    public:
    float aspect_ratio;

    Camera(Entity*);
    Camera(Entity*, const float&);

    void UpdateCameraMatrix();
    sml::mat4 CameraMatrix();
    
    float GetSize() const;
    void SetSize(const float&);
};

}

#endif
*/