#ifndef GLEWY_MOUSE_HPP
#define GLEWY_MOUSE_HPP

#include<substd/vec.hpp>
#include<Glewy/Input/inputable.hpp>

namespace gly{

class Mouse : Inputable {
friend class Instance;
private:
    ss::vec2<double> position;
    
    void Update() override;

    Mouse(Instance*);

public:
    ss::vec2<double> GetPosition();
    ss::vec2<int> GetPixelPosition();
    ss::vec2<double> GetNormalizedPosition();
};

}

#endif