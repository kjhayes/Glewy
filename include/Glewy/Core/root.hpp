#ifndef GLEWY_ROOT_HPP
#define GLEWY_ROOT_HPP

#include<list>

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
    std::list<RenderableCache*> active_materials;

public:
    Root();
    ~Root();

    std::list<Entity*> entity_registry;
    
    Entity* CreateEntity();
    Entity* CreateEntity(Transform*);
    void DestroyEntity(Entity*);
    void UpdateEntities(const UpdateInfo&);

    Camera* camera;
    void LoadRenderable(Renderable*);
    void UnloadRenderable(Renderable*);

    void CallRenderables();
    void RenderWith(Renderer*);
};

}

#endif