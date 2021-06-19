#ifndef GLEWY_RENDERABLECACHE_HPP
#define GLEWY_RENDERABLECACHE_HPP

#include<Glewy/Structures/cache.hpp>

namespace gly{

class Material;
class Renderable;

typedef Cache<Material*, Renderable*> RenderableCache;

}

#endif //GLEWY_RENDERABLECACHE_HPP