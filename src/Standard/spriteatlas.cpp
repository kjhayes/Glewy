#include<Glewy/Standard/spriteatlas.hpp>

#include<Glewy/Rendering/shaders.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Scene/entity.hpp>
#include<Glewy/Core/root.hpp>
#include<Glewy/Rendering/uniform.hpp>
#include<Glewy/Rendering/rendercalls.hpp>
#include<Glewy/Rendering/texture.hpp>
#include<Glewy/Rendering/texcoordtable.hpp>

namespace gly{

Material* SpriteAtlas::sprite_atlas_material_default = nullptr;

SpriteAtlas::SpriteAtlas(Entity* e):Attachment(e),index(0){
    if(sprite_atlas_material_default == nullptr){
        sprite_atlas_material_default = new Material(Shaders::transform_texture_vert, Shaders::transform_texture_atlas_frag, false);
    }
    this->SetMaterial(sprite_atlas_material_default);
}

SpriteAtlas::~SpriteAtlas(){GetEntity()->GetRoot()->UnloadRenderable(this);}

void SpriteAtlas::SetTexture(Texture* tex){
    this->texture = tex;
    GetEntity()->GetRoot()->LoadRenderable(this);
}
Texture* SpriteAtlas::GetTexture(){return texture;}

void SpriteAtlas::SetTexCoordTable(TexCoordTable* tct){
    texcoordtable = tct;
    SetIndex(index);
}
TexCoordTable* SpriteAtlas::GetTexCoordTable(){return texcoordtable;}

void SpriteAtlas::SetIndex(const int& i){
    if(i<0){index = texcoordtable->size;}
    else if(i>=texcoordtable->size){index = 0;}
    else{index = i;}
}
int SpriteAtlas::GetIndex(){return index;}

void SpriteAtlas::Render(){
    Uniform gly_transform(GetMaterial(), "gly_transform");
    Uniform gly_texture(GetMaterial(), "gly_texture");
    Uniform gly_atlas_offset(GetMaterial(), "gly_atlas_offset");
    Uniform gly_atlas_size(GetMaterial(), "gly_atlas_size");

    Uniform::SetUniform(&gly_transform, GetEntity()->GetTransform());
    Uniform::SetUniform(&gly_texture, texture);
    texture->Bind();
    Uniform::SetUniform(&gly_atlas_offset, texcoordtable->coords[index].offset);
    Uniform::SetUniform(&gly_atlas_size, texcoordtable->coords[index].size);

    RenderCalls::RenderQuad();
}

}