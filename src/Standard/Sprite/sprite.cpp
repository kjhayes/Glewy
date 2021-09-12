#include<Glewy/Standard/Sprite/sprite.hpp>

#include<substd/mat.hpp>

#include<Glewy/Core/logging.hpp>

#define GLEW_STATIC
#include<GL/glew.h>

#include<Glewy/Rendering/rendercalls.hpp>
#include<Glewy/Rendering/uniform.hpp>
#include<Glewy/Core/root.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/texture.hpp>
#include<Glewy/Scene/entity.hpp>
#include<Glewy/Rendering/shaders.hpp>

namespace gly
{

Material* Sprite::sprite_material_default = nullptr;

Sprite::Sprite(Entity* entity):Attachment(entity)
{
	if(sprite_material_default==nullptr){
		sprite_material_default = new Material(Shaders::transform_texture_vert, Shaders::transform_texture_frag, false);
	} 
	SetMaterial(sprite_material_default);
}

Sprite::~Sprite(){
	GetEntity()->GetRoot()->UnloadRenderable(this);
}

Texture* Sprite::GetTexture(){return texture;}
void Sprite::SetTexture(Texture* texture){
	GetEntity()->GetRoot()->LoadRenderable(this);
	this->texture = texture;
}

void Sprite::Render()
{
	Uniform gly_texture(GetMaterial(), "gly_texture");
	Uniform gly_transform(GetMaterial(), "gly_transform");

	Uniform::SetUniform(&gly_texture, texture);
	texture->Bind();
	Uniform::SetUniform(&gly_transform, GetEntity()->GetTransform());

	RenderCalls::RenderQuad();
}

}