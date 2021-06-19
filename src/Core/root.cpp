#include<Glewy/Core/root.hpp>

#include<Glewy/Scene/entity.hpp>
#include<Glewy/Scene/camera.hpp>

#include<Glewy/Core/logging.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/renderer.hpp>
#include<Glewy/Rendering/renderable.hpp>
#include<Glewy/Rendering/renderablecache.hpp>
#include<Glewy/Utilities/util.hpp>

namespace gly
{

Root::Root(){
    camera = new Camera();
    active_materials = new std::list<RenderableCache*>();
    single_play = new std::list<SoundInstance*>();
    loop_play = new std::list<SoundInstance*>();
}

Root::~Root()
{
    for(auto entity = entity_registry.begin(); entity != entity_registry.end(); entity++)
    {
        delete *entity;
    }
    delete camera;
    delete active_materials;

    SilenceAll();
    delete single_play;
    delete loop_play;    
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
    for(auto iter = active_materials->begin(); iter != active_materials->end(); iter++){
        if((*iter)->material == material){(*iter)->CacheRenderable(renderable); return;}
    }
    RenderableCache* cache = new RenderableCache(material); 
    active_materials->push_back(cache);
    cache->CacheRenderable(renderable);
}

void Root::UnloadRenderable(Renderable* renderable){
    renderable->SetRoot(nullptr);
    Material* material = renderable->GetMaterial();
    for(auto iter = active_materials->begin(); iter != active_materials->end(); iter++){
        if((*iter)->material == material){
            (*iter)->DecacheRenderable(renderable); 
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
        (*mat_iter)->material->SetActive();
        (*mat_iter)->material->SetView(camera);
        (*mat_iter)->Render();
    }
}

void Root::RenderWith(Renderer* renderer){
    renderer->SetActive();
    CallRenderables();
    //renderer->WTF(); //WHY THE HELL DOES IT NOT WORK WITHOUT THIS???? (OR USED TO???? (THIS HAS ME VERY CONFUSED BUT IT SEEMS TO WORK SUDDENLY EVEN WITHOUT THIS?))
}

//Audio

std::list<SoundInstance*>* Root::GetSinglePlay(){
    return single_play;
}
std::list<SoundInstance*>* Root::GetLoopPlay(){
    return loop_play;
}
    
SoundInstance* Root::PlaySound(Sound* sound, AudioSettings settings){
    SoundInstance* inst = new SoundInstance(sound, settings);
    single_play->push_back(inst);
    return inst;
}
SoundInstance* Root::PlaySound(Sound* sound, AudioSettings settings, const double& time){
    SoundInstance* inst = new SoundInstance(sound, settings, time);
    single_play->push_back(inst);
    return inst;
}

SoundInstance* Root::LoopSound(Sound* sound, AudioSettings settings){
    SoundInstance* inst = new SoundInstance(sound, settings);
    loop_play->push_back(inst);
    return inst;
}
SoundInstance* Root::LoopSound(Sound* sound, AudioSettings settings, const double& time){
    SoundInstance* inst = new SoundInstance(sound, settings, time);
    loop_play->push_back(inst);
    return inst;
}

bool Root::IsLooping(SoundInstance* sound){
    return ListContains<SoundInstance*>(single_play, sound);
}

void Root::StopLooping(SoundInstance* sound){
    loop_play->remove(sound);
    delete sound;
}

void Root::SilencePlay(){
    for(auto si = single_play->begin(); si != single_play->end(); si++){
        delete (*si);
    }
    single_play->clear();
}
void Root::SilenceLoop(){
    for(auto li = loop_play->begin(); li != loop_play->end(); li++){
        delete (*li);
    }
    loop_play->clear();
}

void Root::SilenceAll(){
    SilencePlay();
    SilenceLoop();
}

}