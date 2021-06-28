#ifndef GLEWY_RENDERABLECACHE_HPP
#define GLEWY_RENDERABLECACHE_HPP

#include<Glewy/Structures/cache.hpp>

namespace gly{

class Material;
class Renderable;

typedef VectorCache<Material*, Renderable*> RenderableCache;

}

#endif //GLEWY_RENDERABLECACHE_HPP