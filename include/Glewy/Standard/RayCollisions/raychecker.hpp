#ifndef GLEWY_RAYCHECKER_HPP
#define GLEWY_RAYCHECKER_HPP

namespace gly{

class RayCollisionGroup;

class RayChecker{
public:
    virtual gly_float AllowedHorizontalMove(const gly_float& attempt, RayCollisionGroup* group) const = 0;
    virtual gly_float AllowedVerticalMove(const gly_float& attempt, RayCollisionGroup* group) const = 0;
    virtual vec2<gly_float> AllowedMove(const vec2<gly_float>& attempt, RayCollisionGroup* group) const = 0;
};

}

#endif