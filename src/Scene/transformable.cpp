#include<Glewy/Scene/transformable.hpp>

#include<Glewy/Structures/transform.hpp>

namespace gly{

Transformable::Transformable(){transform = new Transform();}
Transformable::Transformable(Transform* parent){transform = new Transform(parent);}
Transformable::~Transformable(){delete transform;}
Transform* Transformable::GetTransform(){
    return transform;
}

}