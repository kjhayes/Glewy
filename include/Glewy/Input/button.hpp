#ifndef GLEWY_BUTTON_HPP
#define GLEWY_BUTTON_HPP

#include<Glewy/Input/inputable.hpp>

#include<substd/dool.hpp>

namespace gly{

class Button : Inputable {

public:
    ss::dool active;
    int keycode;

    Button(Instance*);

    void Update() override;

    void SetKeyFromChar(const char&);
};

}

#endif