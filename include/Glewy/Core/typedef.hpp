#ifndef GLEWY_TYPEDEF_HPP
#define GLEWY_TYPEDEF_HPP

#include<substd/vec.hpp>

namespace gly{

///@brief Enum telling the instance class how to format the window aspect ratio.
enum ASPECT_RATIO_OPTION{
    ///@brief Use The Aspect Ratio Of The Current Window's Size
    GLY_USE_WINDOW_AR = 0,
    ///@brief Use The Instance's Current Root's Camera's Aspect Ratio
    GLY_USE_ROOT_AR = 1,
    ///@brief Use The Instance's Custom Aspect Ratio
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