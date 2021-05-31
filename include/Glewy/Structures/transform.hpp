#ifndef GLEWY_TRANSFORM_HPP
#define GLEWY_TRANSFORM_HPP

#include<SML/sml.hpp>
#include<Glewy/Structures/tree.hpp>

namespace gly
{

class Transform : public Tree
{
    friend class Transformable;

    protected:
        bool plugHasChanged = true;
        bool rotationHasChanged = true;

        sml::vec3 position;
        sml::vec3 scale;
        sml::vec3 rotation;

        sml::mat4 plugMatrix;
        sml::mat4 rotationMatrix;
        sml::mat4 matrix;

        void CalculatePlugMatrix();
        void CalculateRotationMatrix();

        void CalculateMatrix();

        Transform();
        Transform(Transform*);

    public:
        sml::mat4 PlugMatrix();
        sml::mat4 RotationMatrix();

        sml::mat4 LocalMatrix();
        sml::mat4 GlobalMatrix();

        sml::vec3 GetPosition() const;
        void SetPosition(const sml::vec3&);
        
        sml::vec3 GetScale() const;
        void SetScale(const sml::vec3&);

        sml::vec3 GetRotation() const;
        void SetRotation(const sml::vec3&);

        Transform* GetParent();
};

}

#endif