#ifndef GLEWY_TRANSFORM_HPP
#define GLEWY_TRANSFORM_HPP

#include<Glewy/Structures/tree.hpp>
#include<Glewy/Structures/mat.hpp>

namespace gly
{

class Transform : public Tree
{
    friend class Transformable;

    protected:
        bool plugHasChanged = true;
        bool rotationHasChanged = true;

        vec3<gly_float> position;
        vec3<gly_float> scale;
        vec3<gly_float> rotation;

        mat4<gly_float> plugMatrix;
        mat4<gly_float> rotationMatrix;
        mat4<gly_float> matrix;

        void CalculatePlugMatrix();
        void CalculateRotationMatrix();

        void CalculateMatrix();

        Transform();
        Transform(Transform*);

    public:
        mat4<gly_float> PlugMatrix();
        mat4<gly_float> RotationMatrix();

        mat4<gly_float> LocalMatrix();
        mat4<gly_float> GlobalMatrix();

        vec3<gly_float> GetPosition() const;
        void SetPosition(const vec3<gly_float>&);
        
        vec3<gly_float> GetScale() const;
        void SetScale(const vec3<gly_float>&);

        vec3<gly_float> GetRotation() const;
        void SetRotation(const vec3<gly_float>&);

        Transform* GetParent();
};

}

#endif