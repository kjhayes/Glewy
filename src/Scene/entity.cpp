#include<Glewy/Scene/entity.hpp>

#include<Glewy/Scene/attachment.hpp>
#include<Glewy/Scene/component.hpp>
#include<Glewy/Structures/transform.hpp>

namespace gly
{

Entity::Entity():Transformable(){
    attachments = new std::list<Attachment*>();
    components = new std::list<Component*>();
}

Entity::Entity(Transform* parent):Transformable(parent){
    attachments = new std::list<Attachment*>();
    components = new std::list<Component*>();
}

Entity::~Entity(){
    delete attachments;
    delete components;
}

void Entity::UpdateComponents(const UpdateInfo& info)
{
    for(auto comp = components->begin(); comp != components->end(); comp++)
    {(*comp)->Update(info);}
}

void Entity::RecieveAttachment(Attachment* att){
    attachments->push_back(att);
    if(att->IsComponent()){components->push_back(dynamic_cast<Component*>(att));}
}

void Entity::RemoveAttachment(Attachment* att){
    attachments->remove(att);
    components->remove(dynamic_cast<Component*>(att));
}

void Entity::DeleteAttachment(Attachment* att)
{
    RemoveAttachment(att);
    delete att;
}

void Entity::TransferAttachment(Attachment* att, Entity* other){
    RemoveAttachment(att);
    other->RecieveAttachment(att);
}

Root* Entity::GetRoot(){return root;}

}