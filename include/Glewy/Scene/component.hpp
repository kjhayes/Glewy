#ifndef GLEWY_COMPONENT_HPP
#define GLEWY_COMPONENT_HPP

#include<Glewy/Scene/attachment.hpp>

namespace gly
{

struct UpdateInfo;
class Entity;

class Component : public Attachment
{
    friend class Entity;
    
    protected:
        Component(Entity*);
        virtual void Update(const UpdateInfo&){};
};

}

#endif