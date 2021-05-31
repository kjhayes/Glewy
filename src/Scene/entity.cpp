#include<Glewy/Scene/entity.hpp>

#include<Glewy/Scene/component.hpp>
#include<Glewy/Structures/transform.hpp>

namespace gly
{

Entity::Entity():Transformable(){components = new std::list<Component*>();}
Entity::Entity(Transform* parent):Transformable(parent){components = new std::list<Component*>();}
Entity::~Entity(){delete components;}

void Entity::UpdateComponents(const UpdateInfo& info)
{
    for(auto comp = components->begin(); comp != components->end(); comp++)
    {(*comp)->Update(info);}
}

void Entity::DeleteComponent(Component* comp)
{components->remove(comp);}

Root* Entity::GetRoot(){return root;}

}