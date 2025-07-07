#pragma once

#include "WindowsButton.h"
#include "WindowsCheckbox.h"
#include "../include/GUIFactory.h"

class WindowsFactory : public GUIFactory {
    public:
        Button* createButton() override {
            return new WindowsButton();
        }

        Checkbox* createCheckbox() override {
            return new WindowsCheckbox();
        }
};