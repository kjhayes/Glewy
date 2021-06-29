#ifndef GLEWY_MATH_HPP
#define GLEWY_MATH_HPP

#include<Glewy/Core/typedef.hpp>

namespace gly{

typedef double(&DoubleFloorFunction)(double);
typedef int(&IntAbsFunction)(int);

//Static
class Math{
    static DoubleFloorFunction DoubleFloor;
    static IntAbsFunction IntAbs;
};

}
#endif