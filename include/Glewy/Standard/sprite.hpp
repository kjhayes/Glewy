#ifndef GLEWY_STD_SPRITE_HPP
#define GLEWY_STD_SPRITE_HPP

#include<Glewy/Scene/component.hpp>
#include<Glewy/Rendering/materialrenderable.hpp>

typedef unsigned int GLuint;

namespace gly
{

class Texture;
class Entity;

class Sprite : public Component, public MaterialRenderable
{
protected:
	GLuint VBO;
	static Material* sprite_material_default;

public:
	Sprite(Entity*);
	
	void Update(const UpdateInfo&) override;
	void Render() override;

	Texture* texture;

private:
	void InitVBO();
};

}

#endif