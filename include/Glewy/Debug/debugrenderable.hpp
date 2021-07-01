#ifndef GLEWY_DEBUGRENDERABLE_HPP
#define GLEWY_DEBUGRENDERABLE_HPP

#include<Glewy/Scene/camera.hpp>

namespace gly{

class DebugRenderable {
public:
    virtual void Render() const = 0;
    virtual void Render(const Camera& cam) const = 0;
};

}

#endif