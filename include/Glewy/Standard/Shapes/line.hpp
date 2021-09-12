#ifndef GLEWY_LINE_HPP
#define GLEWY_LINE_HPP

#include<substd/vec.hpp>
#include<Glewy/Core/typedef.hpp>

#include<Glewy/Scene/attachment.hpp>
#include<Glewy/Rendering/renderable.hpp>

//              DO NOT USE LINES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//                  -Only meant for quick visualizations of rays and edges and such
//                  -Terrible performance in the actual application and is terribly badly written

namespace gly{

class Line : public Renderable, public Attachment {
friend class Entity;
public:
    ss::vec2<ss::vec3<gly_float>> end_points;
    ss::vec2<ss::vec4<gly_float>> colors;

protected:
    static Material* default_line_material;

public:
    Line(Entity* e);
    ~Line();

    void Render();

    void SetEndpointX(const ss::vec3<gly_float>& x);
    void SetEndpointY(const ss::vec3<gly_float>& y);

    void SetColorX(const ss::vec4<gly_float>& c_x);
    void SetColorY(const ss::vec4<gly_float>& c_y);
    void SetBothColor(const ss::vec4<gly_float>& color);
};

}

#endif