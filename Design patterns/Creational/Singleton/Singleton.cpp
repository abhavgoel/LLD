#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>

class Singleton {
    private:

    std::string value;
    static Singleton* instance;
    Singleton() {} //private constructor so the objects cannot be created

    public:

    //deleting the copy constructor and assignment operator
    Singleton (Singleton& obj) = delete;
    void operator=(Singleton& obj) = delete;

    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
            return instance;
        }
        return instance;
    }

    void setValue(std::string value) {
        this->value = value;
    }

    std::string getValue() {
        return this->value;
    }
};

Singleton* Singleton::instance = nullptr;

#endif