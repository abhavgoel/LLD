#pragma once

#include <iostream>
#include "../include/Button.h"

class WindowsButton : public Button{
    public:
        void render() override {
            std::cout<<"Rendering a Windows button"<<std::endl;
        }
};