#ifndef GLEWY_DEBUGLINE_HPP
#define GLEWY_DEBUGLINE_HPP

#include<Glewy/Debug/debugrenderable.hpp>

namespace gly{

class Material;

class DebugLine : public DebugRenderable {
private:
    static Material* debug_line_material;

    void Draw() const;

    ss::vec3<gly_float> a, b;
    ss::vec4<gly_float> a_color, b_color;

    void InitMaterial();

public:
    DebugLine(const ss::vec2<gly_float>& a, const ss::vec2<gly_float>& b);
    DebugLine(const ss::vec2<gly_float>& a, const ss::vec2<gly_float>& b, const ss::vec4<gly_float>& color);
    DebugLine(const ss::vec2<gly_float>& a, const ss::vec2<gly_float>& b, const ss::vec4<gly_float>& a_color, const ss::vec4<gly_float>& b_color);

    void Render() const override;
    void Render(const Camera& cam) const override;
};

}

#endif