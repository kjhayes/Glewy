#ifndef GLEWY_TRANSFORM_HPP
#define GLEWY_TRANSFORM_HPP

#include<Glewy/Structures/tree.hpp>
#include<Glewy/Structures/mat.hpp>
#include<Glewy/Structures/modulo.hpp>
#include<Glewy/Structures/rect.hpp>

namespace gly
{

class Transform : public Tree
{
    friend class Transformable;

    protected:
        bool AABBHasChanged = true;
        bool rotationHasChanged = true;

        bool parentHasChanged = true;
        bool childrenAreNotified = true;

        vec3<gly_float> position;
        vec3<gly_float> scale;
        vec3<modulo_tau<gly_float>> rotation;

        mat4<gly_float> aabbMatrix;
        mat4<gly_float> rotationMatrix;
        mat4<gly_float> local_matrix;
        mat4<gly_float> global_matrix;

        virtual void CalculateAABBMatrix();
        void CalculateRotationMatrix();

        void CalculateMatrix();

        Transform();
        Transform(Transform*);

    public:
        mat4<gly_float> AABBMatrix();
        mat4<gly_float> RotationMatrix();

        mat4<gly_float> LocalMatrix();
        mat4<gly_float> GlobalMatrix();

        virtual vec3<gly_float> GetPosition() const;
        virtual void SetPosition(const vec3<gly_float>&);
        
        virtual vec3<gly_float> GetScale() const;
        virtual void SetScale(const vec3<gly_float>&);

        virtual vec3<modulo_tau<gly_float>> GetRotation() const;
        virtual void SetRotation(const vec3<modulo_tau<gly_float>>&);

        Rect<gly_float> GetRect();
        void SetRect(const Rect<gly_float>&);

        Transform* GetParent();

        void NotifyChildren();
};

}

#endif