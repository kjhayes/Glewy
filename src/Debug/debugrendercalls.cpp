#include<Glewy/Debug/debugrendercalls.hpp>

#include<Glewy/Debug/debugline.hpp>

namespace gly{

std::queue<DebugRenderable*> DebugRenderCalls::queue; 

void DebugRenderCalls::Queue(DebugRenderable* r){queue.push(r);}

void DebugRenderCalls::RenderAndClearQueue(const Camera& camera){
    int s = queue.size();
    for(int i = 0; i<s; i++){
        queue.back()->Render(camera);
        delete queue.back();
        queue.pop();
    }
}

void DebugRenderCalls::DrawLine(const vec2<gly_float>& a, const vec2<gly_float>& b){
    Queue(new DebugLine(a,b));
}
void DebugRenderCalls::DrawLine(const vec2<gly_float>& a, const vec2<gly_float>& b, const vec4<gly_float>& color){
    Queue(new DebugLine(a,b,color));
}
void DebugRenderCalls::DrawLine(const vec2<gly_float>& a, const vec2<gly_float>& b, const vec4<gly_float>& a_color, const vec4<gly_float>& b_color){
    Queue(new DebugLine(a,b,a_color,b_color));
}

void DebugRenderCalls::DrawRay(const Ray<gly_float>& ray){
    Queue(new DebugLine(ray.GetOrigin(),ray.GetTip()));
}
void DebugRenderCalls::DrawRay(const Ray<gly_float>& ray, const vec4<gly_float>& color){
    Queue(new DebugLine(ray.GetOrigin(),ray.GetTip(),color));
}
void DebugRenderCalls::DrawRay(const Ray<gly_float>& ray, const vec4<gly_float>& a_color, const vec4<gly_float>& b_color){
    Queue(new DebugLine(ray.GetOrigin(),ray.GetTip(),a_color,b_color));
}

}