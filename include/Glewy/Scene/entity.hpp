#ifndef GLEWY_ENTITY_HPP
#define GLEWY_ENTITY_HPP

#include<Glewy/Core/logging.hpp>
#include<substd/itransformable.hpp>
#include<list>

namespace gly
{

class Root;
class Component;
class Attachment;
struct UpdateInfo;
struct AwakeInfo;

class Entity : public ss::ITransformable
{
    friend class Root;

    protected:
        std::list<Attachment*>* attachments;
        std::list<Component*>* components;

        int root_registry_index;

        void AwakeAttachments(const AwakeInfo&);
        void SleepAttachments(const AwakeInfo&);
        void UpdateComponents(const UpdateInfo&);

        void RecieveAttachment(Attachment*);

    private:
        Root* root;

        Entity();
        Entity(ss::Transform*);
        ~Entity();

    public:
        template<class T> T* AddAttachment()
        {
            T* att = new T(this);
            attachments->push_back(att);
            if(att->IsComponent()){
                components->push_back(dynamic_cast<Component*>(att));
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