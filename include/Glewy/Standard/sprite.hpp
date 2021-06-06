#ifndef GLEWY_SPRITE_HPP
#define GLEWY_SPRITE_HPP

#include<Glewy/Scene/attachment.hpp>
#include<Glewy/Rendering/renderable.hpp>

typedef unsigned int GLuint;

namespace gly
{

class Texture;
class Entity;

class Sprite : public Attachment, public Renderable
{
protected:
	GLuint VBO;
	static Material* sprite_material_default;

public:
	Sprite(Entity*);
	~Sprite();

	void Render() override;

	Texture* texture;

private:
	void InitVBO();
};

}

#endif //GLEWY_SPRITE_HPP