#ifndef GLEWY_DYNRAYBOX_HPP
#define GLEWY_DYNRAYBOX_HPP

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Core/typedef.hpp>


namespace gly{

class RayCollisionGroup;
class Transform;

class DynRayBox{
public:
    Transform* transform;

    gly_int vertical_resolution = 5;
    gly_int horizontal_resolution = 5;

    gly_float AllowedHorizontalMove(const gly_float& attempt, RayCollisionGroup* group) const;
    gly_float AllowedVerticalMove(const gly_float& attempt, RayCollisionGroup* group) const;

    vec2<gly_float> MoveAsAllowed(const vec2<gly_float>& attempt, RayCollisionGroup* group) const;
};

}

#endif