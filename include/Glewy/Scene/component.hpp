#ifndef GLEWY_COMPONENT_HPP
#define GLEWY_COMPONENT_HPP

namespace gly
{

struct UpdateInfo;
class Entity;

class Component
{
    friend class Entity;
    
    protected:
        /// @brief the entity containing this component
        Entity* entity;
        /// @brief called during the intances main loop, if the components root is active
        virtual void Update(const UpdateInfo&){};
        
        Component(Entity*);
        ~Component();
};

}

#endif