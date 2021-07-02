#ifndef GLEWY_DEBUGRENDERCALLS_HPP
#define GLEWY_DEBUGRENDERCALLS_HPP

#include<list>

#include<Glewy/Debug/debugrenderable.hpp>

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Structures/ray.hpp>
#include<Glewy/Structures/rect.hpp>

namespace gly{

//static
class DebugRenderCalls{
    static std::list<DebugRenderable*> queue;

friend class Root;

protected:
    static void RenderAndClearQueue(const Camera& camera);
    static void Queue(DebugRenderable*);

public:
    static void DrawLine(const vec2<gly_float>& a, const vec2<gly_float>& b);
    static void DrawLine(const vec2<gly_float>& a, const vec2<gly_float>& b, const vec4<gly_float>& color);
    static void DrawLine(const vec2<gly_float>& a, const vec2<gly_float>& b, const vec4<gly_float>& a_color, const vec4<gly_float>& b_color);
    
    static void DrawRay(const Ray<gly_float>& ray);
    static void DrawRay(const Ray<gly_float>& ray, const vec4<gly_float>& color);
    static void DrawRay(const Ray<gly_float>& ray, const vec4<gly_float>& a_color, const vec4<gly_float>& b_color);
};

}

#endif