#include<Glewy/Scene/root.hpp>

#include<Glewy/Scene/entity.hpp>
#include<Glewy/Scene/camera.hpp>

namespace gly
{

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

void Root::UpdateEntities(const UpdateInfo& info)
{
    for(auto entity = entity_registry.begin(); entity != entity_registry.end(); entity++)
    {
        (*entity)->UpdateComponents(info);
    }
}

}