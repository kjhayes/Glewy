#include<Glewy/Standard/RayCollisions/dynraybox.hpp>

#include<Glewy/Structures/transform.hpp>
#include<Glewy/Structures/rect.hpp>

#include<Glewy/Utilities/util.hpp>

#include<Glewy/Standard/RayCollisions/raycollisiongroup.hpp>

#include<Glewy/Debug/debugrendercalls.hpp>

namespace gly{

gly_float DynRayBox::AllowedHorizontalMove(const gly_float& attempt, RayCollisionGroup* group) const {
    if(attempt == 0.0f){return attempt;}
    Rect<gly_float> rect = transform->GetGlobalRect();
    gly_float curr_mag = Math::Abs(attempt);
    if(attempt > 0){
        vec2<gly_float> br = rect.GetCorner(BOTTOM_RIGHT);
        std::list<vec2<gly_float>> l = PointsBetween(br, br+vec2<gly_float>(0.0f,rect.dimensions.y), horizontal_resolution);
        for(auto iter = l.begin(); iter != l.end(); iter++){
            curr_mag = group->HorizontalCollide(HorizontalDirRay<gly_float>(*iter, curr_mag));
        }
        return curr_mag;
    }
    else{ //attempt < 0
        vec2<gly_float> bl = rect.GetCorner(BOTTOM_LEFT);
        std::list<vec2<gly_float>> l = PointsBetween(bl, bl+vec2<gly_float>(0.0f,rect.dimensions.y), horizontal_resolution);
        for(auto iter = l.begin(); iter != l.end(); iter++){
            curr_mag = group->HorizontalCollide(HorizontalDirRay<gly_float>(*iter, -curr_mag));
        }
        return -curr_mag;
    }
}
gly_float DynRayBox::AllowedVerticalMove(const gly_float& attempt, RayCollisionGroup* group) const {
    if(attempt == 0.0f){return attempt;}
    Rect<gly_float> rect = transform->GetGlobalRect();
    gly_float curr_mag = Math::Abs(attempt);
    if(attempt > 0){
        vec2<gly_float> tl = rect.GetCorner(TOP_LEFT);
        std::list<vec2<gly_float>> l = PointsBetween(tl, tl+vec2<gly_float>(rect.dimensions.x, 0.0f), vertical_resolution);
        for(auto iter = l.begin(); iter != l.end(); iter++){
            VerticalDirRay<gly_float> ray(*iter, curr_mag);
            curr_mag = group->VerticalCollide(ray);
        }
        return curr_mag;
    }
    else{ //attempt < 0
        vec2<gly_float> bl = rect.GetCorner(BOTTOM_LEFT);
        std::list<vec2<gly_float>> l = PointsBetween(bl, bl+vec2<gly_float>(rect.dimensions.x, 0.0f), vertical_resolution);
        for(auto iter = l.begin(); iter != l.end(); iter++){
            VerticalDirRay<gly_float> ray(*iter, -curr_mag);
            curr_mag = group->VerticalCollide(ray);
        }
        return -curr_mag;
    }
}
vec2<gly_float> DynRayBox::MoveAsAllowed(const vec2<gly_float>& attempt, RayCollisionGroup* group) const{
    vec2<gly_float> dis;
    vec2<gly_float> start_pos = transform->GetLocalPosition();
    dis.x = AllowedHorizontalMove(attempt.x, group);
    if(Math::Abs(dis.x) < Math::Abs(attempt.x) && (dis.x != 0)){
        std::cout<<"X Reduced:";
        //if(dis.x == 0.0f){std::cout<<" (To Zero)";}
        //else{
            std::cout<<"(To "<<dis.x<<")";
        //}
        std::cout<<std::endl;
        }
    transform->SetLocalPositionX(start_pos.x + dis.x);
    dis.y = AllowedVerticalMove(attempt.y, group);
    if(Math::Abs(dis.y) < Math::Abs(attempt.y) && (dis.y != 0)){
        std::cout<<"Y Reduced:";
        //if(dis.y == 0.0f){std::cout<<" (To Zero)";}
        //else{
            std::cout<<"(To "<<dis.y<<")";
        //}
        std::cout<<std::endl;
        }
    transform->SetLocalPositionY(start_pos.y + dis.y);
    return dis;
}

}