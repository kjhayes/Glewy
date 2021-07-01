#ifndef GLEWY_ATTACHMENT_HPP
#define GLEWY_ATTACHMENT_HPP

#include<Glewy/Core/awakeinfo.hpp>

namespace gly{

class Entity;

class Attachment
{
public:
    friend class Entity;
    Entity* GetEntity() const;
    virtual bool IsComponent() const;

    virtual void Awake(const AwakeInfo&);
    virtual void Sleep(const AwakeInfo&);

protected:
    Entity* entity;
    Attachment(Entity* entity);
};

}

#endif //GLEWY_ATTACHMENT_HPP