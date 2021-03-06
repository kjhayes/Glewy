#ifndef GLEWY_RENDERCALLS_HPP
#define GLEWY_RENDERCALLS_HPP

#include<substd/vec.hpp>
#include<Glewy/Core/typedef.hpp>

namespace gly{

class Uniform;
class Transform;
class Texture;

//(Static)
class RenderCalls{
public:
    static void Init();

    static const ss::vec3<gly_float> quad_vertices_default[4];

    //Quad
    static void RenderQuad();

    static void RenderQuads2i(ss::vec2<gly_int>* offsets, const unsigned int& number);

    /*
    static void RenderQuads2f(vec2<gly_float>* offsets, const unsigned int& number);
    static void RenderQuads3i(vec3<gly_int>* offsets, const unsigned int& number);
    static void RenderQuads3f(vec3<gly_float>* offsets, const unsigned int& number);
    */

   //Line
    static void RenderLine();
    static void RenderLine(const gly_float&);
   //
};

}

#endif //GLEWY_RENDERCALLS_HPP