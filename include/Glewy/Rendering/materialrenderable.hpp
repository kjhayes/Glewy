#ifndef GLEWY_MATERIALRENDERABLE_HPP
#define GLEWY_MATERIALRENDERABLE_HPP

namespace gly
{

class Material;

class MaterialRenderable
{
public:
    Material* material;
    virtual void Render() = 0;
};

}

#endif //GLEWY_MATERIALRENDERABLE_HPP