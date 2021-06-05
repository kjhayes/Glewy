#ifndef GLEWY_SAFEPUN_HPP
#define GLEWY_SAFEPUN_HPP

#include<cstring>

namespace gly{

template<typename F, typename T> 
T SafePun(const F& to_pun){
    T ret;
    memcpy(&to_pun, &ret, sizeof(T));
    return ret;
}

}

#endif //GLEWY_SAFEPUN_HPP