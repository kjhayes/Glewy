#ifndef GLEWY_TYPEDEF_HPP
#define GLEWY_TYPEDEF_HPP

#include<substd/vec.hpp>

namespace gly{

enum ASPECT_RATIO_OPTION{
    GLY_USE_WINDOW_AR = 0,
    GLY_USE_ROOT_AR = 1,
    GLY_USE_CUSTOM_AR = 2
};

}

typedef float gly_float;
typedef int gly_int;
typedef unsigned char gly_byte;

using gly_color = ss::vec4<gly_float>;

const static gly_color gly_red(1.0f,0.0f,0.0f,1.0f);
const static gly_color gly_green(0.0f,1.0f,0.0f,1.0f);
const static gly_color gly_blue(0.0f,0.0f,1.0f,1.0f);


#endif