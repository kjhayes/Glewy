#include<Glewy/Core/root.hpp>

#include<Glewy/Scene/entity.hpp>
#include<Glewy/Scene/camera.hpp>

#include<Glewy/Core/logging.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/renderer.hpp>
#include<Glewy/Rendering/renderable.hpp>
#include<Glewy/Rendering/renderablecache.hpp>
#include<Glewy/Utilities/util.hpp>
#include<Glewy/Audio/sound.hpp>
#include<Glewy/Audio/soundinstance.hpp>

namespace gly
{

Root::Root(){
    camera = new Camera();
    active_materials = new std::list<RenderableCache*>();
}

Root::~Root()
{
    for(auto entity = entity_registry.begin(); entity != entity_registry.end(); entity++)
    {
        delete *entity;
    }
    delete camera;
    delete active_materials;  
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

void Root::AwakeEntities(const AwakeInfo& info){
    for(auto entity = entity_registry.begin(); entity != entity_registry.end(); entity++)
    {
        (*entity)->AwakeAttachments(info);
    }
} 
void Root::SleepEntities(const AwakeInfo& info){
    for(auto entity = entity_registry.begin(); entity != entity_registry.end(); entity++)
    {
        (*entity)->SleepAttachments(info);
    }
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
    for(auto iter = active_materials->begin(); iter != active_materials->end(); iter++){
        if((*iter)->grouper == material){(*iter)->CacheThis(renderable); return;}
    }
    RenderableCache* cache = new RenderableCache(material); 
    active_materials->push_back(cache);
    cache->CacheThis(renderable);
}

void Root::UnloadRenderable(Renderable* renderable){
    renderable->SetRoot(nullptr);
    Material* material = renderable->GetMaterial();
    for(auto iter = active_materials->begin(); iter != active_materials->end(); iter++){
        if((*iter)->grouper == material){
            (*iter)->DecacheThis(renderable); 
            if((*iter)->IsEmpty()){
                active_materials->remove((*iter));
                delete (*iter);
            }
            return;
        }
    }
}

void Root::CallRenderables(){
    for(auto mat_iter = active_materials->begin(); mat_iter != active_materials->end(); mat_iter++){
        (*mat_iter)->grouper->SetActive();
        (*mat_iter)->grouper->SetView(camera);
        for(auto iter = (*mat_iter)->cache.begin(); iter != (*mat_iter)->cache.end(); iter++){
            (*iter)->Render();
        }
    }
}

void Root::RenderWith(Renderer* renderer){
    renderer->SetActive();
    CallRenderables();
    //renderer->WTF(); //WHY THE HELL DOES IT NOT WORK WITHOUT THIS???? (OR USED TO???? (THIS HAS ME VERY CONFUSED BUT IT SEEMS TO WORK SUDDENLY EVEN WITHOUT THIS?))
}

}