#include<Glewy/Rendering/renderablecache.hpp>

#include<Glewy/Core/logging.hpp>
#include<Glewy/Rendering/renderable.hpp>

namespace gly{

RenderableCache::RenderableCache(Material* material):material(material){}

bool RenderableCache::IsEmpty(){
    if(cache.size() == 0){return true;}
    return false;
}

void RenderableCache::CacheRenderable(Renderable* renderable){
    cache.push_back(renderable); 
}

void RenderableCache::DecacheRenderable(Renderable* renderable){
    cache.remove(renderable);
}

void RenderableCache::Render(){
    for(auto iter = cache.begin(); iter != cache.end(); iter++){
        (*iter)->Render();
    }
}

}