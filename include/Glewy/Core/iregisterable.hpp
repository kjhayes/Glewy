#ifndef GLEWY_IREGISTERABLE_HPP
#define GLEWY_IREGISTERABLE_HPP

#include<list>

namespace gly{

template<class self>
class IRegisterable 
{
public:
    static std::list<self*> registry;
    IRegisterable(){
        registry.push_back((self*)this);
    }
    ~IRegisterable(){
        registry.remove((self*)this);
    }
};
template<class self> std::list<self*> IRegisterable<self>::registry;

}

#endif //GLEWY_IREGISTERABLE_HPP