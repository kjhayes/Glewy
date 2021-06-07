#ifndef GLEWY_RENDERCALLS_HPP
#define GLEWY_RENDERCALLS_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

class Uniform;
class Transform;
class Texture;

//(Static)
class RenderCalls{
public:
    static void Init();

    static const vec3<gly_float> quad_vertices_default[4];

    static void RenderQuad();
};

}

#endif //GLEWY_RENDERCALLS_HPP