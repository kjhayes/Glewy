#include<Glewy/Standard/spriteatlas.hpp>

#include<cstdlib>

#include<Glewy/Rendering/shaders.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Scene/entity.hpp>
#include<Glewy/Core/root.hpp>
#include<Glewy/Rendering/uniform.hpp>
#include<Glewy/Rendering/rendercalls.hpp>
#include<Glewy/Rendering/texture.hpp>

namespace gly{

Material* SpriteAtlas::sprite_atlas_material_default = nullptr;

SpriteAtlas::SpriteAtlas(Entity* e):Attachment(e),atlas_size(1.0f,1.0f),atlas_offset(0.0f,0.0f),index(0),dimensions(1,1){
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

void SpriteAtlas::SetDimensions(const vec2<gly_int>& dim){
    this->dimensions = dim;
    atlas_size.x = 1.0f/(float)dim.x;
    atlas_size.y = 1.0f/(float)dim.y; 
    SetIndex(index);
}

void SpriteAtlas::SetIndex(int ind){
    int tot = dimensions.x*dimensions.y;
    if(ind >= tot){ind = ind % tot;}
    while (ind<0){ind += tot;}
    this->index = ind;
    div_t division = div(ind, dimensions.x);
    atlas_offset.x = division.rem * atlas_size.x;
    atlas_offset.y = division.quot * atlas_size.y;
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
    Uniform::SetUniform(&gly_atlas_offset, atlas_offset);
    Uniform::SetUniform(&gly_atlas_size, atlas_size);

    RenderCalls::RenderQuad();
}

}