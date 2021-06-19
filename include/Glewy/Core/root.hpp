#ifndef GLEWY_ROOT_HPP
#define GLEWY_ROOT_HPP

#include<list>
#include<Glewy/Audio/soundinstance.hpp>

namespace gly
{

class Instance;

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

public:
    Root();
    ~Root();

    Instance* is_current_root_of = nullptr;

//Entity
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
};

}

#endif