#pragma once
#include "../include/Checkbox.h"
#include <iostream>

class MacCheckbox : public Checkbox {
public:
    void render() override {
        std::cout << "Rendering Mac Checkbox" << std::endl;
    }
}; 