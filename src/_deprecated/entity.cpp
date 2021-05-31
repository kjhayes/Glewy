#include<Glewy/deprecated/entity.hpp>

namespace gly
{

Entity::Entity(Entity* parent)
{
    if(parent!=nullptr){parent->AddChild(this);}
    else{delete this;}
}

sml::mat4 Entity::Matrix() 
{
    UpdateMatrix();
    return ((Entity*)parent)->Matrix() * this->matrix;
}

void Entity::PropagateUpdate(const UpdateCall& call)
{
    this->Update(call);
    for(int i = 0; i < children.size(); i++)
    {((Entity*)children[i])->PropagateUpdate(call);}
}

void Entity::Update(const UpdateCall& call){}

void Entity::PropagateRender(const RenderCall& call)
{
    this->Render(call);
    for(int i = 0; i < children.size(); i++)
    {((Entity*)children[i])->PropagateRender(call);}
}

void Entity::Render(const RenderCall& call){}

}