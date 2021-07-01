#include<Glewy/Debug/debugline.hpp>

#include<Glewy/Rendering/rendercalls.hpp>

#include<Glewy/Rendering/shaders.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/uniform.hpp>

#include<Glewy/Scene/camera.hpp>

namespace gly{

Material* DebugLine::debug_line_material = nullptr;

DebugLine::DebugLine(
    const vec2<gly_float>& a, 
    const vec2<gly_float>& b
    ): a(a), b(b), a_color(1.0f,1.0f,1.0f,1.0f), b_color(1.0f,1.0f,1.0f,1.0f) 
{
    InitMaterial();
}
DebugLine::DebugLine(
        const vec2<gly_float>& a, 
        const vec2<gly_float>& b, 
        const vec4<gly_float>& color
        ): a(a), b(b), a_color(color), b_color(color)
{
    InitMaterial();
}
DebugLine::DebugLine(
        const vec2<gly_float>& a, 
        const vec2<gly_float>& b, 
        const vec4<gly_float>& a_color, 
        const vec4<gly_float>& b_color
        ): a(a), b(b), a_color(a_color), b_color(b_color)
{
    InitMaterial();
}


void DebugLine::InitMaterial(){
    if(debug_line_material == nullptr){debug_line_material = new Material(Shaders::default_line_vert, Shaders::default_line_frag, false);}
}

void DebugLine::Render() const {
    debug_line_material->SetActive();
    Uniform gly_view(debug_line_material, "gly_view");
    Uniform::SetUniform(&gly_view, mat4<gly_float>());

    Draw();
}

void DebugLine::Render(const Camera& cam) const {
    debug_line_material->SetActive();
    debug_line_material->SetView(cam);

    Draw();
}

void DebugLine::Draw() const {
    Uniform pos_x(debug_line_material, "gly_pos_x");
    Uniform pos_y(debug_line_material, "gly_pos_y");
    Uniform color_x(debug_line_material, "gly_color_x");
    Uniform color_y(debug_line_material, "gly_color_y");
    
    Uniform::SetUniform(&pos_x, a);
    Uniform::SetUniform(&pos_y, b);
    Uniform::SetUniform(&color_x, a_color);
    Uniform::SetUniform(&color_y, b_color);

    RenderCalls::RenderLine();
}

}