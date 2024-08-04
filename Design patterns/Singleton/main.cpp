#include<iostream>
#include "Singleton.cpp"

int main() {
    Singleton* singleton1 = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();
    
    singleton1->setValue("Abhav");
    std::cout<<singleton1->getValue()<<std::endl;

    singleton2->setValue("Goel") ;
    std::cout<<singleton2->getValue()<<std::endl;

    std::cout<<"Printing Address of instances"<<std::endl;
    std::cout<<"singleton1's address: "<<singleton1<<std::endl;
    std::cout<<"singleton2's address: "<<singleton2<<std::endl;


}