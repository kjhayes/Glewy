#ifndef GLEWY_CAMERACONTROLLER_HPP
#define GLEWY_CAMERACONTROLLER_HPP

#include<substd/vec.hpp>
#include<Glewy/Core/typedef.hpp>
#include<Glewy/Scene/component.hpp>

namespace ss{
    class Transform;
}

namespace gly{

class Entity;
class Button;

class TransformController : public Component{
friend class gly::Entity;

public:
    ss::vec2<gly_float> speed = {1.0f,1.0f};
    gly_float zoom_speed = 1.1f;

    void SetTransform(ss::Transform*);

protected:
    TransformController(Entity* e);
    
    ss::Transform* transform;

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