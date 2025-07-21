#pragma once

#include "Button.h"
#include "Checkbox.h"

class GUIFactory {
    public:
        virtual Button* createButton() = 0;
        virtual Checkbox* createCheckbox() = 0;
};