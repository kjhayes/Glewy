#ifndef GLEWY_MOUSE_HPP
#define GLEWY_MOUSE_HPP

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Input/inputable.hpp>

namespace gly{

class Mouse : Inputable {
friend class Instance;
private:
    vec2<double> position;
    
    void Update() override;

    Mouse(Instance*);

public:
    vec2<double> GetPosition();
    vec2<int> GetPixelPosition();
    vec2<double> GetNormalizedPosition();
};

}

#endif