#ifndef GLEWY_ATTACHMENT_HPP
#define GLEWY_ATTACHMENT_HPP

namespace gly{

class Entity;

class Attachment
{
public:
    friend class Entity;
    Entity* GetEntity();
    virtual bool IsComponent();

protected:
    Entity* entity;
    Attachment(Entity* entity);
};

}

#endif //GLEWY_ATTACHMENT_HPP