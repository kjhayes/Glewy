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
    void CalculateLocalAABBMatrix() const override;

public:
    Camera();
    Camera(Transform*);

    float GetAspectRatio();
    void SetAspectRatio(const float&);

    void SetSize(const gly_float&);

    void SetLocalPosition(const vec3<gly_float>&) override;

    void SetLocalPositionX(const gly_float&) override;
    void SetLocalPositionY(const gly_float&) override;
    void SetLocalPositionZ(const gly_float&) override;

    void SetLocalScale(const vec3<gly_float>&) override;

    void SetLocalScaleX(const gly_float&) override;
    void SetLocalScaleY(const gly_float&) override;
    void SetLocalScaleZ(const gly_float&) override;

    void SetLocalRotation(const vec3<modulo_tau<gly_float>>&) override;

    void SetLocalRotationX(const modulo_tau<gly_float>&) override;
    void SetLocalRotationY(const modulo_tau<gly_float>&) override;
    void SetLocalRotationZ(const modulo_tau<gly_float>&) override;

    vec3<gly_float> GetLocalPosition() const override;    
    vec3<gly_float> GetLocalScale() const override;
    vec3<modulo_tau<gly_float>> GetLocalRotation() const override;
};

}

#endif