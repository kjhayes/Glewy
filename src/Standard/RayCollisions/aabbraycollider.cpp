#include<Glewy/Standard/RayCollisions/aabbraycollider.hpp>

#include<Glewy/Scene/entity.hpp>
#include<Glewy/Structures/transform.hpp>
#include<Glewy/Utilities/intersection.hpp>

namespace gly{

AABBRayCollider::AABBRayCollider(Entity* e):Attachment(e){}

AABBRayCollider::RCReturnType AABBRayCollider::Collide(const RCRay& ray) const {
    return ray.GetMagnitude();
}

AABBRayCollider::RCReturnType AABBRayCollider::HorizontalCollide(const RCRay& ray) const {
    vec2<RCType> bl = GetEntity()->GetTransform()->GetGlobalRect().GetCorner(BOTTOM_LEFT);
    vec2<RCType> tr = GetEntity()->GetTransform()->GetGlobalRect().GetCorner(TOP_RIGHT);
    vec2<RCType> origin = ray.GetOrigin();
    vec2<RCType> dir = ray.GetDirection();
    
    if(!Math::ExclusiveBetween(SortedRange<RCType>(bl.y,tr.y), origin.y)){
        return Math::Abs<RCType>(dir.x);
    }
    SortedRange<RCType> x_range = SortedRange<RCType>(bl.x,tr.x);
    if(Math::ExclusiveBetween(x_range, origin.x)){return Math::Abs<RCType>(dir.x);}
    else{
        return Math::Abs<RCType>(LinearRayHit<RCType>(origin.x, dir.x, Math::Nearest<RCType>(x_range, origin.x)));
    }
}

AABBRayCollider::RCReturnType AABBRayCollider::VerticalCollide(const RCRay& ray) const {
    vec2<RCType> bl = GetEntity()->GetTransform()->GetGlobalRect().GetCorner(BOTTOM_LEFT);
    vec2<RCType> tr = GetEntity()->GetTransform()->GetGlobalRect().GetCorner(TOP_RIGHT);
    vec2<RCType> origin = ray.GetOrigin();
    vec2<RCType> dir = ray.GetDirection();
    if(!Math::ExclusiveBetween(SortedRange<RCType>(bl.x,tr.x), origin.x)){
        return Math::Abs<RCType>(dir.y);
    }
    SortedRange<RCType> y_range = SortedRange<RCType>(bl.y,tr.y);
    if(Math::ExclusiveBetween(y_range, origin.y)){return Math::Abs<RCType>(dir.y);}
    else{
        return Math::Abs<RCType>(LinearRayHit<RCType>(origin.y, dir.y, Math::Nearest<RCType>(y_range, origin.y)));
    }
}

}