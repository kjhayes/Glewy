#ifndef GLEWY_INVERSETRANSFORM_HPP
#define GLEWY_INVERSETRANSFORM_HPP

#include<Glewy/Structures/transform.hpp>

namespace gly{

class InverseTransform : public Transform
{
friend class Camera;
protected:
    InverseTransform();
    InverseTransform(Transform*);

public:
    void SetPosition(const vec3<gly_float>&) override;
    void SetScale(const vec3<gly_float>&) override;
    void SetRotation(const vec3<modulo_tau<gly_float>>&) override;

    vec3<gly_float> GetPosition() const override;    
    vec3<gly_float> GetScale() const override;
    vec3<modulo_tau<gly_float>> GetRotation() const override;
};

}

#endif //GLEWY_INVERSETRANSFORM_HPP