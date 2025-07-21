#include <iostream>
#include "WindowsFactory.h"
#include "MacFactory.h"
#include "../include/GUIFactory.h"

int main() {
    std::string os;
    std::cout<<"Enter a OS "<<std::endl;
    std::cout<<"1. Windows"<<std::endl;
    std::cout<<"2. Mac"<<std::endl;

    std::cin>>os;
    GUIFactory* factory;

    if(os == "1") {
        factory = new WindowsFactory();
    } else {
        factory = new MacFactory();
    }

    Button* btn = factory->createButton();
    Checkbox* chkbx = factory->createCheckbox();

    btn->render();
    chkbx->render();
}