#ifndef GLEWY_ROOT_HPP
#define GLEWY_ROOT_HPP

#include<list>
#include<Glewy/Audio/soundinstance.hpp>

#include<Glewy/Rendering/renderablecache.hpp>

namespace ss{
    class Transform;
}

namespace gly
{

class Instance;

class Entity;
struct UpdateInfo;
struct AwakeInfo;
class Camera;

class Renderer;
class Renderable;

class Root 
{
private:
//Render
    std::list<RenderableCache*>* active_materials;

public:
    Root();
    ~Root();

//Entity
    std::list<Entity*> entity_registry;
    
    Entity* CreateEntity();
    Entity* CreateEntity(ss::Transform*);
    void DestroyEntity(Entity*);

    void AwakeEntities(const AwakeInfo&);
    void SleepEntities(const AwakeInfo&);
    void UpdateEntities(const UpdateInfo&);

//Render
    Camera* camera;
    void LoadRenderable(Renderable*);
    void UnloadRenderable(Renderable*);

    void CallRenderables();
    void RenderWith(Renderer*);
};

}

#endif