#ifndef GLEWY_SPRITEATLAS_HPP
#define GLEWY_SPRITEATLAS_HPP

//FIRST FRAME BOTTOM LEFT, LAST FRAME TOP RIGHT

#include<Glewy/Rendering/renderable.hpp>
#include<Glewy/Scene/attachment.hpp>
#include<Glewy/Structures/vec.hpp>

namespace gly{

class Texture;
class TexCoordTable;

class SpriteAtlas : public Renderable, public Attachment {

protected:
    static Material* sprite_atlas_material_default;

private:
    Texture* texture;
    TexCoordTable* texcoordtable;
    int index;

public:
    SpriteAtlas(Entity* entity);
    ~SpriteAtlas();

    void Render() override;

    void SetTexture(Texture*);
    Texture* GetTexture();

    void SetTexCoordTable(TexCoordTable*);
    TexCoordTable* GetTexCoordTable();
    
    void SetIndex(const int&);
    int GetIndex();
};

}

#endif //GLEWY_SPRITEATLAS_HPP