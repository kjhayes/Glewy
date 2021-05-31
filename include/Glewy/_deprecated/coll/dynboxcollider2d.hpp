#ifndef GLEWY_DYNBOXCOLLIDER2D_HPP
#define GLEWY_DYNBOXCOLLIDER2D_HPP

#include<cmath>
#include<list>
#include<Glewy/entity.hpp>
#include<Glewy/component.hpp>
#include<Glewy/collider2d.hpp>

namespace gly
{

class DynBoxCollider2D : public Component
{
	friend class Entity;

	DynBoxCollider2D(Entity* e):Component(e){}

	public:	
	sml::vec2 velocity;
	
	sml::vec2 bottom_left = {-0.5f,-0.5f};
	sml::vec2 top_right = {0.5f,0.5f};

	sml::vec2 drag = {6.0f, 6.0f};
	sml::vec2 max_velocity = {10.0f, 10.0f};
	sml::vec2 min_velocity = {-10.0f, -10.0f};

	void Update(const UpdateInfo&) override;
	void ApplyNormals();
	void TryMove(const sml::vec2&);
	
	std::list<sml::vec2> PointsBetween(const sml::vec2&, const sml::vec2&, const int&);
};

}

#endif