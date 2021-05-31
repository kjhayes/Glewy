#include<Glewy/raycollider2d.hpp>
#include<Glewy/entity.hpp>
#include<Glewy/util.hpp>

namespace gly
{

RayCollider2D::RayCollider2D(Entity* e):Collider2D(e),a(-0.5,0.5),b(0.5,0.5){}

void RayCollider2D::ClosestCollision(Ray2D& ray, Collision2D& coll)
{
    sml::vec4 a4(a,0.0f,1.0f);
    a4 = entity->transform.GlobalMatrix().VecMult(a4);
    sml::vec2 o = sml::vec2(a4.x, a4.y);
    sml::vec4 b4(b,0.0f,1.0f);
    b4 = entity->transform.GlobalMatrix().VecMult(b4);
    sml::vec2 d = {b4.x-a4.x, b4.y-a4.y};

    float denominator = (ray.dir.x*d.y) - (ray.dir.y*d.x);
    if(denominator==0.0f){return;}
    sml::vec2 o_dif = ray.origin - o;
    float t_numerator = (o_dif.y*d.x) - (o_dif.x*d.y);
    float u_numerator = (ray.dir.x*o_dif.y) - (ray.dir.y*o_dif.x);
    if(denominator>0.0f)
    {
        if((t_numerator<0.0f) || (u_numerator<0.0f)){return;}
        if((t_numerator>denominator) || (u_numerator>denominator)){return;}
    }
    else
    {
        if((t_numerator>0.0f) || (u_numerator>0.0f)){return;}
        if((t_numerator<denominator) || (u_numerator<denominator)){return;}
    }
        
    ray.dir*=(t_numerator/denominator);
    coll.normal = GetNormal(d);
    coll.collider = this;
}

void RayCollider2D::Collisions(const Ray2D& ray, std::list<Collision2D>& collision_list) 
{
    sml::vec4 a4(a,0.0f,1.0f);
    a4 = entity->transform.GlobalMatrix().VecMult(a4);
    sml::vec2 o = sml::vec2(a4.x, a4.y);
    sml::vec4 b4(b,0.0f,1.0f);
    b4 = entity->transform.GlobalMatrix().VecMult(b4);
    sml::vec2 d = {b4.x-a4.x, b4.y-a4.y};
    
    float denominator = (ray.dir.x*d.y) - (ray.dir.y*d.x);
    if(denominator==0.0f){return;}
    sml::vec2 o_dif = ray.origin - o;
    float t_numerator = (o_dif.y*d.x) - (o_dif.x*d.y);
    float u_numerator = (ray.dir.x*o_dif.y) - (ray.dir.y*o_dif.x);
    if(denominator>0.0f)
    {
        if((t_numerator<0.0f) || (u_numerator<0.0f)){return;}
        if((t_numerator>denominator) || (u_numerator>denominator)){return;}
    }
    else
    {
        if((t_numerator>0.0f) || (u_numerator>0.0f)){return;}
        if((t_numerator<denominator) || (u_numerator<denominator)){return;}
    }
    Collision2D coll;
    coll.collider = this;
    coll.point =  (ray.dir*(t_numerator/denominator)) + ray.origin;
    coll.normal = GetNormal(d); 
    collision_list.push_back(coll);
}

sml::vec2 RayCollider2D::GetNormal(const sml::vec2& d)
{
    sml::vec2 n = Util::normalized(d);
    return sml::vec2(-n.y,n.x);
}

}