#ifndef GLEWY_SPRITE_HPP
#define GLEWY_SPRITE_HPP

#include<Glewy/Rendering/renderable.hpp>
#include<Glewy/Scene/attachment.hpp>

typedef unsigned int GLuint;

namespace gly
{

class Transform;
class Texture;

class Sprite : public Renderable, public Attachment
{
protected:
	static Material* sprite_material_default;

public:	
	
	Sprite(Entity*);
	~Sprite();

	void SetTexture(Texture*);
	Texture* GetTexture();

	void Render() override;

private:
	Texture* texture;
};

}

#endif //GLEWY_SPRITE_HPP