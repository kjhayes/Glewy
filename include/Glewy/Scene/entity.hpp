#ifndef GLEWY_ENTITY_HPP
#define GLEWY_ENTITY_HPP

#include<Glewy/Core/logging.hpp>
#include<Glewy/Scene/transformable.hpp>
#include<list>
#include<type_traits>

namespace gly
{

class Root;
class Component;
class Attachment;
struct UpdateInfo;

class Entity : public Transformable
{
    friend class Root;

    protected:
        std::list<Attachment*>* attachments;
        std::list<Component*>* components;

        int root_registry_index;
        void UpdateComponents(const UpdateInfo&);

        void RecieveAttachment(Attachment*);

    private:
        Root* root;

        Entity();
        Entity(Transform*);
        ~Entity();

    public:
        template<class T> T* AddAttachment()
        {
            T* att = new T(this);
            attachments->push_back(att);
            if(std::is_base_of<Component, T>()){
                components->push_back((Component*)att);
            }
	        return att;
        };
        template<class T> T* GetAttachment()
        {
            for(auto attachment = attachments->begin(); attachment != attachments->end(); attachment++)
            {
                T* t = dynamic_cast<T*>(*attachment);
                if(t!=nullptr){return t;}
            }
            return nullptr;
        };
        void RemoveAttachment(Attachment*);
        void DeleteAttachment(Attachment*);
        void TransferAttachment(Attachment*, Entity*);

        Root* GetRoot();
};

}

#endif