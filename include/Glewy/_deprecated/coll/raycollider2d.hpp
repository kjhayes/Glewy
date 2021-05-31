#ifndef GLEWY_RAYCOLLIDER2D_HPP
#define GLEWY_RAYCOLLIDER2D_HPP

#include<Glewy/ray.hpp>
#include<Glewy/collider2d.hpp>

namespace gly
{

class RayCollider2D : public Collider2D
{
    public:
    sml::vec2 a;
    sml::vec2 b;

    RayCollider2D(Entity*);

    void ClosestCollision(Ray2D&, Collision2D&) override;
    
    void Collisions(const Ray2D&, std::list<Collision2D>&) override;

    sml::vec2 GetNormal(const sml::vec2&);
};

}

#endif