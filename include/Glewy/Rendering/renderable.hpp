#ifndef GLEWY_MATERIALRENDERABLE_HPP
#define GLEWY_MATERIALRENDERABLE_HPP

#include<list>

namespace gly
{

class Material;
class Root;

class Renderable
{
private:
    Root* active_in = nullptr;
    Material* material;

public:    
    virtual void Render() = 0;
    
    void SetMaterial(Material* material);
    Material* GetMaterial();

    void SetRoot(Root*);
};

}

#endif //GLEWY_MATERIALRENDERABLE_HPP