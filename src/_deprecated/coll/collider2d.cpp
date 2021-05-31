#include<Glewy/collider2d.hpp>

namespace gly
{
std::list<Collider2D*> Collider2D::registry;

Collider2D::Collider2D(Entity* entity):Component(entity){registry.push_back(this);}
Collider2D::~Collider2D(){registry.remove(this);}

Collision2D Collider2D::GetClosestCollision(const Ray2D& r)
{
    Ray2D ray = r;
    Collision2D coll;
    coll.collider = nullptr;
    for(auto iter = registry.begin(); iter != registry.end(); iter++)
    {
        (*iter)->ClosestCollision(ray, coll);
    }
    coll.point = ray.dir + ray.origin;
    return coll;
}

std::list<Collision2D> Collider2D::GetCollisions(const Ray2D& ray)
{
    std::list<Collision2D> collisions;
    for(auto iter = registry.begin(); iter != registry.end(); iter++)
    {
        (*iter)->Collisions(ray, collisions);
    }
    return collisions;
}

}