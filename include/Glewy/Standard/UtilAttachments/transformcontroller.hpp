#ifndef GLEWY_CAMERACONTROLLER_HPP
#define GLEWY_CAMERACONTROLLER_HPP

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Core/typedef.hpp>
#include<Glewy/Scene/component.hpp>

namespace gly{

class Entity;
class Button;
class Transform;

class TransformController : public Component{
friend class gly::Entity;

public:
    vec2<gly_float> speed = {1.0f,1.0f};
    gly_float zoom_speed = 1.1f;

    void SetTransform(Transform*);

protected:
    TransformController(Entity* e);
    
    Transform* transform;

    Button* W;
    Button* A;
    Button* S;
    Button* D;
    Button* Q;
    Button* E;

    void Awake(const AwakeInfo& info) override;
    void Sleep(const AwakeInfo& info) override;

    void Update(const UpdateInfo& info) override;
};


}

#endif