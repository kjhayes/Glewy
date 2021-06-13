#include<Glewy/Content/stringserial.hpp>

#include<sstream>
#include<iostream>

namespace gly{

template<> int StringTo<int>(const std::string& str){
    std::stringstream stream(str);
    int ret;
    stream >> ret;
    return ret;
}
template<> float StringTo<float>(const std::string& str){
    std::stringstream stream(str);
    float ret;
    stream >> ret;
    return ret;
}
template<> double StringTo<double>(const std::string& str){
    std::stringstream stream(str);
    double ret;
    stream >> ret;
    return ret;
}
}