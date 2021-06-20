#ifndef GLEWY_BUTTON_HPP
#define GLEWY_BUTTON_HPP

#include<Glewy/Input/inputable.hpp>

#include<Glewy/Structures/dool.hpp>

namespace gly{

class Button : Inputable {

public:
    dool active;
    int keycode;

    Button(Instance*);

    void Update() override;

    void SetKeyFromChar(const char&);
};

}

#endif