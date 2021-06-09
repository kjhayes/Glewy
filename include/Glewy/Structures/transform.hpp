#ifndef GLEWY_TRANSFORM_HPP
#define GLEWY_TRANSFORM_HPP

#include<Glewy/Structures/tree.hpp>
#include<Glewy/Structures/mat.hpp>
#include<Glewy/Structures/modulo.hpp>

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
        vec3<modulo_tau<gly_float>> rotation;

        mat4<gly_float> plugMatrix;
        mat4<gly_float> rotationMatrix;
        mat4<gly_float> matrix;

        virtual void CalculatePlugMatrix();
        void CalculateRotationMatrix();

        void CalculateMatrix();

        Transform();
        Transform(Transform*);

    public:
        mat4<gly_float> PlugMatrix();
        mat4<gly_float> RotationMatrix();

        mat4<gly_float> LocalMatrix();
        mat4<gly_float> GlobalMatrix();

        virtual vec3<gly_float> GetPosition() const;
        virtual void SetPosition(const vec3<gly_float>&);
        
        virtual vec3<gly_float> GetScale() const;
        virtual void SetScale(const vec3<gly_float>&);

        virtual vec3<modulo_tau<gly_float>> GetRotation() const;
        virtual void SetRotation(const vec3<modulo_tau<gly_float>>&);

        Transform* GetParent();
};

}

#endif