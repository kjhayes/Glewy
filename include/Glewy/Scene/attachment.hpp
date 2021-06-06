#ifndef GLEWY_ATTACHMENT_HPP
#define GLEWY_ATTACHMENT_HPP

namespace gly{

class Entity;

class Attachment
{
public:
    friend class Entity;
    virtual Entity* GetEntity();

protected:
    Entity* entity;
    Attachment(Entity* entity);
};

}

#endif //GLEWY_ATTACHMENT_HPP