#ifndef GLEWY_CAMERA_HPP
#define GLEWY_CAMERA_HPP

#include<Glewy/Core/typedef.hpp>

#include<substd/transform.hpp>
#include<substd/mat.hpp>

namespace gly
{

class Camera : public ss::Transform
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

    void SetLocalPosition(const ss::vec3<gly_float>&) override;

    void SetLocalPositionX(const gly_float&) override;
    void SetLocalPositionY(const gly_float&) override;
    void SetLocalPositionZ(const gly_float&) override;

    void SetLocalScale(const ss::vec3<gly_float>&) override;

    void SetLocalScaleX(const gly_float&) override;
    void SetLocalScaleY(const gly_float&) override;
    void SetLocalScaleZ(const gly_float&) override;

    void SetLocalRotation(const ss::vec3<ss::modulo_tau<gly_float>>&) override;

    void SetLocalRotationX(const ss::modulo_tau<gly_float>&) override;
    void SetLocalRotationY(const ss::modulo_tau<gly_float>&) override;
    void SetLocalRotationZ(const ss::modulo_tau<gly_float>&) override;

    ss::vec3<gly_float> GetLocalPosition() const override;    
    ss::vec3<gly_float> GetLocalScale() const override;
    ss::vec3<ss::modulo_tau<gly_float>> GetLocalRotation() const override;
};

}

#endif