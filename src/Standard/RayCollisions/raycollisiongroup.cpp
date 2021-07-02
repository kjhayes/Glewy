#include<Glewy/Standard/RayCollisions/raycollisiongroup.hpp>

#include<Glewy/Utilities/math.hpp>

namespace gly{

RayCollisionGroup::RayCollisionGroup(){colliders = new std::list<RayCollidable*>();}
RayCollisionGroup::~RayCollisionGroup(){delete colliders;}

RCReturnType RayCollisionGroup::Collide(const RCRay& ray) const {
    RCReturnType ret = ray.GetMagnitude();
    for(auto iter = colliders->begin(); iter != colliders->end(); iter++){
        RCReturnType curr = (*iter)->Collide(ray);
        if(Math::Abs(curr)<Math::Abs(ret)){ret = curr;}
    }
    return ret;
}
RCReturnType RayCollisionGroup::HorizontalCollide(const RCRay& ray) const {
    RCReturnType ret = ray.GetMagnitude();
    for(auto iter = colliders->begin(); iter != colliders->end(); iter++){
        RCReturnType curr = (*iter)->HorizontalCollide(ray);
        ret = Math::Min(ret, curr);
    }
    return ret;
}
RCReturnType RayCollisionGroup::VerticalCollide(const RCRay& ray) const {
    RCReturnType ret = ray.GetMagnitude();
    for(auto iter = colliders->begin(); iter != colliders->end(); iter++){
        RCReturnType curr = (*iter)->VerticalCollide(ray);
        ret = Math::Min(ret, curr);
    }
    return ret;
}

void RayCollisionGroup::AddCollider(RayCollidable* r){colliders->push_back(r);}
void RayCollisionGroup::RemoveCollider(RayCollidable* r){colliders->remove(r);}

}