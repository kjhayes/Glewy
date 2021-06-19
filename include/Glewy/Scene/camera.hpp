#ifndef GLEWY_CAMERA_HPP
#define GLEWY_CAMERA_HPP

#include<Glewy/Structures/transform.hpp>
#include<Glewy/Structures/mat.hpp>

namespace gly
{

class Camera : public Transform
{
protected:
    float size;
    float aspect_ratio;
    
    void CalculateScale();
    void CalculateAABBMatrix() override;

public:
    Camera();
    Camera(Transform*);

    float GetAspectRatio();
    void SetAspectRatio(const float&);

    void SetSize(const float&);
    float GetSize();

    void SetPosition(const vec3<gly_float>&) override;
    void SetScale(const vec3<gly_float>&) override;
    void SetRotation(const vec3<modulo_tau<gly_float>>&) override;

    vec3<gly_float> GetPosition() const override;    
    vec3<gly_float> GetScale() const override;
    vec3<modulo_tau<gly_float>> GetRotation() const override;
};

}

#endif