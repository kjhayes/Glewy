#ifndef GLEWY_TYPEDEF_HPP
#define GLEWY_TYPEDEF_HPP

#include<Glewy/Structures/vec.hpp>

namespace gly{

enum ASPECT_RATIO_OPTION{
    GLY_USE_WINDOW_AR = 0,
    GLY_USE_ROOT_AR = 1,
    GLY_USE_CUSTOM_AR = 2
};

enum CORNER{
    BOTTOM_LEFT = 0,
    BOTTOM_RIGHT = 1,
    TOP_LEFT = 2,
    TOP_RIGHT = 3
};

}

typedef float gly_float;
typedef int gly_int;
typedef unsigned char gly_byte;

constexpr double gly_pi = 3.14159265358979323846;
constexpr double gly_tau = 6.28318530717958647692;
constexpr double gly_pi_div_180 = 0.01745329251;
constexpr double gly_180_div_pi = 57.2957795131;

using gly_color = gly::vec4<gly_float>;

const static gly_color gly_red(1.0f,0.0f,0.0f,1.0f);
const static gly_color gly_green(0.0f,1.0f,0.0f,1.0f);
const static gly_color gly_blue(0.0f,0.0f,1.0f,1.0f);


#endif