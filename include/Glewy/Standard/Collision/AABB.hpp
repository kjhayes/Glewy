#ifndef GLEWY_AABB_HPP
#define GLEWY_AABB_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

class Transform;

class AABB{

    static bool IsColliding(Transform* a, Transform* b);
    static vec2<gly_float> CollisionArea(Transform* a, Transform* b);

};

}

#endif