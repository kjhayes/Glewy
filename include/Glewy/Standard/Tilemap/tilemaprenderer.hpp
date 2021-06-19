#ifndef GLEWY_TILEMAPRENDERER_HPP
#define GLEWY_TILEMAPRENDERER_HPP

#include<Glewy/Rendering/renderable.hpp>
#include<Glewy/Scene/attachment.hpp>

namespace gly{

class Tilemap;

class TilemapRenderer : public Renderable, public Attachment {
protected:
	static Material* tilemap_material_default;

public:	
	TilemapRenderer(Entity*);
	~TilemapRenderer();

	void SetTilemap(Tilemap*);
	Tilemap* GetTilemap();

	void Render() override;

private:
	Tilemap* tilemap;
};

}

#endif