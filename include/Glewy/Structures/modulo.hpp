#ifndef GLEWY_MODULO_HPP
#define GLEWY_MODULO_HPP

#include<Glewy/Core/imodifiable.hpp>
#include<cmath>

namespace gly{

template<class self, typename T>
class modular {
public:
    static constexpr T Modulus();
};

template<class T>
class modulo_tau : public modular<modulo_tau<T>, T>, public IModifiable<T>{
public:
    modulo_tau(const T& t):IModifiable<T>(t){}
    constexpr T Modulus() {
        return (T)gly_tau;
    }
    T EvalValue(const T& t) override {return fmod(t, Modulus());}
    inline void operator=(const T& eq){return IModifiable<T>::operator=(eq);}
};

}

#endif //GLEWY_MODULO_HPP