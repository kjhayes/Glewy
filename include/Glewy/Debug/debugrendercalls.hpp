#ifndef GLEWY_DEBUGRENDERCALLS_HPP
#define GLEWY_DEBUGRENDERCALLS_HPP

#include<list>

#include<Glewy/Debug/debugrenderable.hpp>
#include<Glewy/Core/typedef.hpp>

#include<substd/vec.hpp>
#include<substd/ray.hpp>
#include<substd/rect.hpp>

namespace gly{

//static
class DebugRenderCalls{
    static std::list<DebugRenderable*> queue;

friend class Root;

protected:
    static void RenderAndClearQueue(const Camera& camera);
    static void Queue(DebugRenderable*);

public:
    static void DrawLine(const ss::vec2<gly_float>& a, const ss::vec2<gly_float>& b);
    static void DrawLine(const ss::vec2<gly_float>& a, const ss::vec2<gly_float>& b, const ss::vec4<gly_float>& color);
    static void DrawLine(const ss::vec2<gly_float>& a, const ss::vec2<gly_float>& b, const ss::vec4<gly_float>& a_color, const ss::vec4<gly_float>& b_color);
    
    static void DrawRay(const ss::Ray<gly_float>& ray);
    static void DrawRay(const ss::Ray<gly_float>& ray, const ss::vec4<gly_float>& color);
    static void DrawRay(const ss::Ray<gly_float>& ray, const ss::vec4<gly_float>& a_color, const ss::vec4<gly_float>& b_color);
};

}

#endif