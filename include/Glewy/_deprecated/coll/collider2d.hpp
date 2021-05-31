#ifndef GLEWY_COLLIDER2D_HPP
#define GLEWY_COLLIDER2D_HPP

#include<list>

#include<Glewy/component.hpp>
#include<SML/sml.hpp>
#include<Glewy/ray.hpp>


namespace gly
{

class Collider2D;

struct Collision2D
{
    Collider2D* collider = nullptr;
    sml::vec2 point; // Point of Collision
    sml::vec2 normal; //Normal of Collision
};

class Collider2D : public Component
{
    protected:
    static std::list<Collider2D*> registry;

    Collider2D(Entity*);
    ~Collider2D();

    public:
    static Collision2D GetClosestCollision(const Ray2D&);    
    static std::list<Collision2D> GetCollisions(const Ray2D&);

    virtual void ClosestCollision(Ray2D&, Collision2D&) = 0;
    virtual void Collisions(const Ray2D&, std::list<Collision2D>&) = 0;
};

}

#endif