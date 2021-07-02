#ifndef GLEWY_RCAABB_HPP
#define GLEWY_RCAABB_HPP

//rc stands for raycollidable
#include<Glewy/Standard/RayCollisions/raycollidable.hpp>

#include<Glewy/Structures/rect.hpp>

#include<Glewy/Structures/range.hpp>
#include<Glewy/Utilities/math.hpp>
#include<Glewy/Utilities/intersection.hpp>

#include<Glewy/Scene/attachment.hpp>
#include<Glewy/Scene/entity.hpp>
#include<Glewy/Core/root.hpp>
#include<Glewy/Structures/transform.hpp>

#include<Glewy/Debug/debugrendercalls.hpp>

namespace gly{

class RCAABB : public Attachment, public RayCollidable {
friend class gly::Entity;
protected:
    RCAABB(Entity* e):Attachment(e){}

public: 
    RCReturnType Collide(const RCRay& ray) const override {
        return ray.GetMagnitude();
    }

    RCReturnType HorizontalCollide(const RCRay& ray) const override {
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
    RCReturnType VerticalCollide(const RCRay& ray) const override {
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
};

}

#endif