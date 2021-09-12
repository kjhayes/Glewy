#include<Glewy/Content/stringserial.hpp>

#include<sstream>
#include<iostream>

namespace gly{

int PositionOfNextMarker(const std::string& str, const int& start_pos, const char* markers, const int& number_of_markers){
    int minimum_position = str.length();
    for(int i = 0; i<number_of_markers; i++){
        int pos = str.find_first_of(markers[i], start_pos);
        if(pos == std::string::npos){pos = str.length();}
        if(pos < minimum_position){minimum_position = pos;}
    }
    return minimum_position;
}

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
template<> ss::vec2<gly_int> StringTo<ss::vec2<gly_int>>(const std::string& str){
    int c = 0;
    gly_int* arr = StringToArray<gly_int>(str, c, ',');
    if(c>=2){
        ss::vec2<gly_int> v(arr[0],arr[1]);
        delete arr;
        return v;
    }
    else{
        delete arr;
        return {0,0};
    }
}

}