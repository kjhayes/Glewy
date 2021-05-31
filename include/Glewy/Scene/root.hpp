#ifndef GLEWY_ROOT_HPP
#define GLEWY_ROOT_HPP

#include<list>

namespace gly
{

class Entity;
class Transform;
struct UpdateInfo;
class Camera;

class Root 
{
public:
    std::list<Entity*> entity_registry;
    Camera* camera;

    Entity* CreateEntity();
    Entity* CreateEntity(Transform*);
    void DestroyEntity(Entity*);

    Root();
    ~Root();

    void UpdateEntities(const UpdateInfo&);
};

}

#endif