#ifndef GLEWY_RENDERABLECACHE_HPP
#define GLEWY_RENDERABLECACHE_HPP

#include<list>

namespace gly{

class Material;
class Renderable;

class RenderableCache{
public:
    RenderableCache(Material*);

    bool IsEmpty();

    void CacheRenderable(Renderable*);
    void DecacheRenderable(Renderable*);

    void Render();

    const Material* material;

private:
    std::list<Renderable*> cache;
};

}

#endif //GLEWY_RENDERABLECACHE_HPP