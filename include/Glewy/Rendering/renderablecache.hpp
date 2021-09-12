#ifndef GLEWY_RENDERABLECACHE_HPP
#define GLEWY_RENDERABLECACHE_HPP

#include<substd/cache.hpp>

namespace gly{

class Material;
class Renderable;

typedef ss::VectorCache<Material*, Renderable*> RenderableCache;

}

#endif //GLEWY_RENDERABLECACHE_HPP