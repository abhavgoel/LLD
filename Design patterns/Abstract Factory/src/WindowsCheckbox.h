#pragma once

#include <iostream>
#include "../include/Checkbox.h"

class WindowsCheckbox : public Checkbox {
    void render () override {
        std::cout<<"Rendering a Windows Checkbox"<<std::endl;
    }
};
