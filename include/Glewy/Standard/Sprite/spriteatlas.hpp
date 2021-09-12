#ifndef GLEWY_SPRITEATLAS_HPP
#define GLEWY_SPRITEATLAS_HPP

#include<Glewy/Rendering/renderable.hpp>
#include<Glewy/Scene/attachment.hpp>
#include<substd/vec.hpp>

namespace gly{

class Texture;
class UVTable;

class SpriteAtlas : public Renderable, public Attachment {

protected:
    static Material* sprite_atlas_material_default;

private:
    Texture* texture;
    UVTable* uvtable;
    int index;

public:
    SpriteAtlas(Entity* entity);
    ~SpriteAtlas();

    void Render() override;

    void SetTexture(Texture*);
    Texture* GetTexture();

    void SetUVTable(UVTable*);
    UVTable* GetUVTable();

    void SetIndex(const int&);
    int GetIndex();
};

}

#endif //GLEWY_SPRITEATLAS_HPP