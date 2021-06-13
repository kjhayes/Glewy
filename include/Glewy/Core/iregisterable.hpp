#ifndef GLEWY_IREGISTERABLE_HPP
#define GLEWY_IREGISTERABLE_HPP

#include<list>

namespace gly{

template<class self, class storage=std::list<self*>>
class IRegisterable 
{
public:
    static storage registry;
    IRegisterable(){
        registry.push_back((self*)this);
    }
    ~IRegisterable(){
        registry.remove((self*)this);
    }
};
template<class self, class storage> storage IRegisterable<self, storage>::registry;

}

#endif //GLEWY_IREGISTERABLE_HPP