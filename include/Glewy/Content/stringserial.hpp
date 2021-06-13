#ifndef GLEWY_STRINGSERIAL_HPP
#define GLEWY_STRINGSERIAL_HPP

#include<string>

namespace gly{

template<class T> T StringTo(const std::string&);

template<class T> T* StringToArray(const std::string& str, int& count, const char& comma=','){
    count = 1;
    for (int i = 0; i < str.length(); i++)
    {if(str[i] == comma){count++;}}
    
    T* arr = new T[count];
    
    int s_pos = 0;
    for(int i = 0; i < count; i++){
        int comma_pos = str.find_first_of(comma, s_pos);
        if(comma_pos == std::string::npos){comma_pos = str.length();}
        arr[i] = StringTo<T>(str.substr(s_pos, comma_pos-s_pos));
        s_pos = comma_pos+1;
    }
    return arr;
}

template<> int StringTo<int>(const std::string&);
template<> float StringTo<float>(const std::string&);
template<> double StringTo<double>(const std::string&);

}

#endif