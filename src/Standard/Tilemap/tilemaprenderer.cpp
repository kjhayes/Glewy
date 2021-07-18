#include<Glewy/Standard/Tilemap/tilemaprenderer.hpp>

#include<Glewy/Standard/Tilemap/tilemap.hpp>

#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/shaders.hpp>

#include<Glewy/Core/root.hpp>
#include<Glewy/Scene/entity.hpp>

#include<Glewy/Rendering/uniform.hpp>
#include<Glewy/Rendering/texture.hpp>
#include<Glewy/Structures/uvtable.hpp>

#include<Glewy/Rendering/rendercalls.hpp>

#include<Glewy/Structures/transform.hpp>

namespace gly{

Material* TilemapRenderer::tilemap_material_default;

TilemapRenderer::TilemapRenderer(Entity* e):Attachment(e){
    if(tilemap_material_default==nullptr){
		tilemap_material_default = new Material(Shaders::transform_texture_instance2i_vert, Shaders::transform_texture_frag, false);
	} 
	SetMaterial(tilemap_material_default);
}

TilemapRenderer::~TilemapRenderer(){
    GetEntity()->GetRoot()->UnloadRenderable(this);
}

Tilemap* TilemapRenderer::GetTilemap(){return tilemap;}
void TilemapRenderer::SetTilemap(Tilemap* t){tilemap = t; GetEntity()->GetRoot()->LoadRenderable(this);}

void TilemapRenderer::Render(){

    Uniform gly_transform(GetMaterial(), "gly_transform");
    Uniform gly_texture(GetMaterial(), "gly_texture");
    Uniform gly_atlas_offset(GetMaterial(), "gly_atlas_offset");
    Uniform gly_atlas_size(GetMaterial(), "gly_atlas_size");

    Uniform::SetUniform(&gly_transform, GetEntity()->GetTransform());

    for(auto tilecache = tilemap->active_tiles->begin(); tilecache != tilemap->active_tiles->end(); tilecache++){

        Tile* tile = (*tilecache)->grouper;

        Uniform::SetUniform(&gly_texture, tile->texture);
    
        tile->texture->Bind();
    
        Uniform::SetUniform(&gly_atlas_offset, tile->uvtable->GetCoords()[tile->index_in_table].offset);
        Uniform::SetUniform(&gly_atlas_size, tile->uvtable->GetCoords()[tile->index_in_table].size);

        RenderCalls::RenderQuads2i((*tilecache)->cache.data(), (*tilecache)->cache.size());    
    }
}

}