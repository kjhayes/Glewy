#ifndef GLEWY_TRANSFORMABLE_HPP
#define GLEWY_TRANSFORMABLE_HPP

namespace gly{

class Transform;

class Transformable
{
protected:
    Transform* transform;
public:
    Transformable();
    Transformable(Transform* parent);
    ~Transformable();
    Transform* GetTransform();
};

}

#endif //GLEWY_TRANSFORMABLE_HPP