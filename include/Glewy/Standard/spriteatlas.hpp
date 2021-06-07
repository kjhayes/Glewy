#ifndef GLEWY_SPRITEATLAS_HPP
#define GLEWY_SPRITEATLAS_HPP

//FIRST FRAME BOTTOM LEFT, LAST FRAME TOP RIGHT

#include<Glewy/Rendering/renderable.hpp>
#include<Glewy/Scene/attachment.hpp>
#include<Glewy/Structures/vec.hpp>

namespace gly{

class Texture;

class SpriteAtlas : public Renderable, public Attachment {

protected:
    static Material* sprite_atlas_material_default;

private:
    Texture* texture;
    vec2<gly_float> atlas_size;
    vec2<gly_float> atlas_offset;
    int index;
    vec2<gly_int> dimensions;

public:
    SpriteAtlas(Entity* entity);
    ~SpriteAtlas();

    void Render() override;

    void SetTexture(Texture*);
    Texture* GetTexture();

    void SetDimensions(const vec2<gly_int>&);
    void SetIndex(int);
    int GetIndex();
};

}

#endif //GLEWY_SPRITEATLAS_HPP