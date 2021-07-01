#include<Glewy/Standard/RayCollisions/raycollidable.hpp>

namespace gly{

RCReturnType RayCollidable::Collide(const RCRay& ray) const {return ray.GetMagnitude();}
RCReturnType RayCollidable::HorizontalCollide(const RCRay& ray) const {return Collide(ray);}
RCReturnType RayCollidable::VerticalCollide(const RCRay& ray) const {return Collide(ray);}

}