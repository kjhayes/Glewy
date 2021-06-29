#ifndef GLEWY_CAMERA_HPP
#define GLEWY_CAMERA_HPP

#include<Glewy/Structures/transform.hpp>
#include<Glewy/Structures/mat.hpp>

namespace gly
{

class Camera : public Transform
{
protected:
    float aspect_ratio;
    
    void CalculateScale();
    void CalculateAABBMatrix() override;

public:
    Camera();
    Camera(Transform*);

    float GetAspectRatio();
    void SetAspectRatio(const float&);

    void SetSize(const gly_float&);

    void SetPosition(const vec3<gly_float>&) override;

    void SetPositionX(const gly_float&) override;
    void SetPositionY(const gly_float&) override;
    void SetPositionZ(const gly_float&) override;

    void SetScale(const vec3<gly_float>&) override;

    void SetScaleX(const gly_float&) override;
    void SetScaleY(const gly_float&) override;
    void SetScaleZ(const gly_float&) override;

    void SetRotation(const vec3<modulo_tau<gly_float>>&) override;

    void SetRotationX(const modulo_tau<gly_float>&) override;
    void SetRotationY(const modulo_tau<gly_float>&) override;
    void SetRotationZ(const modulo_tau<gly_float>&) override;

    vec3<gly_float> GetPosition() const override;    
    vec3<gly_float> GetScale() const override;
    vec3<modulo_tau<gly_float>> GetRotation() const override;
};

}

#endif