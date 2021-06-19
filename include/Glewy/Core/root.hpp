#ifndef GLEWY_ROOT_HPP
#define GLEWY_ROOT_HPP

#include<list>
#include<Glewy/Audio/soundinstance.hpp>

namespace gly
{

class Entity;
class Transform;
struct UpdateInfo;
class Camera;

class Renderer;
class Renderable;
class RenderableCache;

class Root 
{
private:
//Render
    std::list<RenderableCache*>* active_materials;
//Audio
    std::list<SoundInstance*>* single_play;
    std::list<SoundInstance*>* loop_play;

public:
    Root();
    ~Root();

    std::list<Entity*> entity_registry;
    
    Entity* CreateEntity();
    Entity* CreateEntity(Transform*);
    void DestroyEntity(Entity*);
    void UpdateEntities(const UpdateInfo&);

//Render
    Camera* camera;
    void LoadRenderable(Renderable*);
    void UnloadRenderable(Renderable*);

    void CallRenderables();
    void RenderWith(Renderer*);

//Audio
    std::list<SoundInstance*>* GetSinglePlay();
    std::list<SoundInstance*>* GetLoopPlay();

    SoundInstance* PlaySound(Sound* sound, AudioSettings settings);
    SoundInstance* PlaySound(Sound* sound, AudioSettings settings, const double& time);

    SoundInstance* LoopSound(Sound* sound, AudioSettings settings);
    SoundInstance* LoopSound(Sound* sound, AudioSettings settings, const double& time);

    bool IsLooping(SoundInstance* sound);

    void StopLooping(SoundInstance* sound);

    void SilencePlay();
    void SilenceLoop();

    void SilenceAll();
};

}

#endif