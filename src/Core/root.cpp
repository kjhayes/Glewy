#include<Glewy/Core/root.hpp>

#include<Glewy/Scene/entity.hpp>
#include<Glewy/Scene/camera.hpp>

#include<Glewy/Core/logging.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/renderer.hpp>
#include<Glewy/Rendering/renderable.hpp>
#include<Glewy/Rendering/renderablecache.hpp>

namespace gly
{

Root::Root(){
    camera = new Camera();
}

Root::~Root()
{
    for(auto entity = entity_registry.begin(); entity != entity_registry.end(); entity++)
    {
        delete *entity;
    }
    delete camera;
}


Entity* Root::CreateEntity()
{
    Entity* entity = new Entity(nullptr);
    entity_registry.push_back(entity);
    entity->root = this;
    return entity;
}
Entity* Root::CreateEntity(Transform* parent)
{
    Entity* entity = new Entity(parent);
    entity_registry.push_back(entity);
    entity->root = this;
    return entity;
}

void Root::DestroyEntity(Entity* entity)
{
    delete entity;
    entity_registry.remove(entity);
}
void Root::UpdateEntities(const UpdateInfo& info)
{
    for(auto entity = entity_registry.begin(); entity != entity_registry.end(); entity++)
    {
        (*entity)->UpdateComponents(info);
    }
}

void Root::LoadRenderable(Renderable* renderable){
    renderable->SetRoot(this);
    Material* material = renderable->GetMaterial();
    for(auto iter = active_materials.begin(); iter != active_materials.end(); iter++){
        if((*iter)->material == material){(*iter)->CacheRenderable(renderable); return;}
    }
    RenderableCache* cache = new RenderableCache(material); 
    active_materials.push_back(cache);
    cache->CacheRenderable(renderable);
}

void Root::UnloadRenderable(Renderable* renderable){
    renderable->SetRoot(nullptr);
    Material* material = renderable->GetMaterial();
    for(auto iter = active_materials.begin(); iter != active_materials.end(); iter++){
        if((*iter)->material == material){
            (*iter)->DecacheRenderable(renderable); 
            if((*iter)->IsEmpty()){
                active_materials.remove((*iter));
                delete (*iter);
            }
            return;
        }
    }
}

void Root::CallRenderables(){
    for(auto mat_iter = active_materials.begin(); mat_iter != active_materials.end(); mat_iter++){
        (*mat_iter)->material->SetActive();
        (*mat_iter)->material->SetView(camera);
        (*mat_iter)->Render();
    }
}

void Root::RenderWith(Renderer* renderer){
    renderer->SetActive();
    renderer->Clear();
    CallRenderables();
    //renderer->WTF(); //WHY THE HELL DOES IT NOT WORK WITHOUT THIS???? (OR USED TO???? (THIS HAS ME VERY CONFUSED BUT IT SEEMS TO WORK SUDDENLY EVEN WITHOUT THIS?))
}

}