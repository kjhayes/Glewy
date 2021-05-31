#ifndef GLEWY_ENTITY_HPP
#define GLEWY_ENTITY_HPP

#include<Glewy/Scene/transformable.hpp>
#include<list>

namespace gly
{

class Root;
class Component;
struct UpdateInfo;

class Entity : public Transformable
{
    friend class Root;

    protected:
        std::list<Component*>* components;

        int root_registry_index;
        void UpdateComponents(const UpdateInfo&);

    private:
        Root* root;

        Entity();
        Entity(Transform*);
        ~Entity();

    public:
        template<class T> T* AddComponent()
        {
	        T* comp = new T(this);
	        components->push_back(comp);
	        return comp;
        };
        template<class T> T* GetComponent()
        {
            for(auto comp = components->begin(); comp != components->end(); comp++)
            {
                T* t = dynamic_cast<T*>(*comp);
                if(t!=nullptr){return t;}
            }
            return nullptr;
        };
        void DeleteComponent(Component*);

        Root* GetRoot();
};

}

#endif