#ifndef GLEWY_ENTITY_HPP
#define GLEWY_ENTITY_HPP

#include<Glewy/tree.hpp>
#include<Glewy/transform.hpp>
#include<vector>

namespace gly
{

struct RenderCall;
struct UpdateCall;

class Entity : public Tree, public Transform
{
	protected:
	Entity(){};

	public:
	Entity(Entity*);

	virtual sml::mat4 Matrix() override;

	void PropagateRender(const RenderCall&);
	virtual void Render(const RenderCall&);

	void PropagateUpdate(const UpdateCall&);
	virtual void Update(const UpdateCall&);
};

}

#endif