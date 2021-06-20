#ifndef GLEWY_INPUTABLE_HPP
#define GLEWY_INPUTABLE_HPP

#include<Glewy/Core/iregisterable.hpp>

namespace gly{

class Instance;

class Inputable : IRegisterable<Inputable> {
friend class Instance;
protected:
    virtual void Update() = 0;
public:
    Instance* instance;
    Inputable(Instance*);
};

}

#endif