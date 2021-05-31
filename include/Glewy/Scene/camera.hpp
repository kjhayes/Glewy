#ifndef GLEWY_CAMERA_HPP
#define GLEWY_CAMERA_HPP

#include<Glewy/Scene/transformable.hpp>

namespace sml{
    class mat4;
}

namespace gly
{

class Camera : Transformable
{
    protected:
    /// @brief 1 / Camera Size
    float size_reciprocal;

    public:
    Camera();

    /// @brief Width/Height, where Height is assumed 1.0f
    float aspect_ratio;
    /// @brief Depth of View, Does Nothing Currently
    float depth;

    /// @brief  Accounts Only For Global Position, Not Rotation or Scale
    /// @return View Matrix of This Camera
    sml::mat4 ViewMatrix() const;

    /// @brief Set Camera Size
    void SetSize(const float&);
    /// @return Camera Size
    float GetSize();
};

}

#endif