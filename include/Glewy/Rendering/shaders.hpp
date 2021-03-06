#ifndef GLEWY_SHADERS_HPP
#define GLEWY_SHADERS_HPP

namespace gly{

//(Static)
class Shaders{

public:
    static const char* default_vert;
    static const char* default_frag;

    static const char* solid_color_frag;

    static const char* default_line_vert;
    static const char* default_line_frag;

    static const char* transform_texture_vert;
    static const char* transform_texture_frag;
    
    static const char* transform_texture_atlas_frag;

    static const char* renderer_vert;
    static const char* renderer_frag;

    static const char* transform_texture_instance2i_vert;
};

}

#endif //GLEWY_SHADERS_HPP