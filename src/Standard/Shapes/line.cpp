#include<Glewy/Standard/Shapes/line.hpp>

#include<Glewy/Scene/entity.hpp>
#include<Glewy/Core/root.hpp>

#include<Glewy/Rendering/rendercalls.hpp>

#include<Glewy/Rendering/shaders.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/uniform.hpp>

/*

Brief Note: LINES SUCK CURRENTLY (DO NOT ACTUALLY USE FOR ANY REASON OTHER THAN VERY SMALL AMOUNTS OF DEBUG VISUALIZATION)

*/

namespace gly{

Material* Line::default_line_material = nullptr;

Line::Line(Entity* e):Attachment(e),end_points({0,0,0},{0,0,0}),colors({1,1,1,1},{1,1,1,1}){
    if(Line::default_line_material == nullptr){default_line_material = new Material(Shaders::default_line_vert, Shaders::default_line_frag, false);}
    SetMaterial(default_line_material);
    GetEntity()->GetRoot()->LoadRenderable(this);
}
Line::~Line(){GetEntity()->GetRoot()->UnloadRenderable(this);}

void Line::Render(){
    Uniform pos_x(GetMaterial(), "gly_pos_x");
    Uniform pos_y(GetMaterial(), "gly_pos_y");
    Uniform color_x(GetMaterial(), "gly_color_x");
    Uniform color_y(GetMaterial(), "gly_color_y");
    
    Uniform::SetUniform(&pos_x, end_points.x);
    Uniform::SetUniform(&pos_y, end_points.y);
    Uniform::SetUniform(&color_x, colors.x);
    Uniform::SetUniform(&color_y, colors.y);

    RenderCalls::RenderLine();    
}

void Line::SetEndpointX(const vec3<gly_float>& x){
    end_points.x = x;
}
void Line::SetEndpointY(const vec3<gly_float>& y){
    end_points.y = y;
}

void Line::SetColorX(const vec4<gly_float>& c_x){
    colors.x = c_x;
}
void Line::SetColorY(const vec4<gly_float>& c_y){
    colors.y = c_y;
}
void Line::SetBothColor(const vec4<gly_float>& color){
    colors.x = color;
    colors.y = color;
}


}