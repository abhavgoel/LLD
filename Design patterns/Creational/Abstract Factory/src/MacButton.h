#pragma once
#include "../include/Button.h"
#include <iostream>

class MacButton : public Button {
public:
    void render() override {
        std::cout << "Rendering Mac Button" << std::endl;
    }
}; 