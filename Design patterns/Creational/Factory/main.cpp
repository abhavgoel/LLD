#include<iostream>
using namespace std;

class IGameObject {
    public:
        virtual ~IGameObject();
        virtual void Update() = 0;
        virtual void Render() = 0;

};

IGameObject::~IGameObject() {}

class Car : public IGameObject {
    public:
        Car(){
            cout<<"Car object"<<endl;
        }
        void Update(){}
        void Render(){
            cout<<"Rendering a Car"<<endl;
        }

};

class Boat : public IGameObject {
    public:
        Boat(){
            cout<<"Boat object"<<endl;
        }
        void Update(){}
        void Render(){
            cout<<"Rendering a Boat"<<endl;
        }
};

enum class GameObjectType {CAR, BOAT};

IGameObject* makeGameObjectFactory(GameObjectType type) {
    if(type == GameObjectType::BOAT) {
        return new Boat();
    } else if (type == GameObjectType::CAR) {
        return new Car();
    }
    return nullptr;
}

int main() {
    IGameObject *obj1 = makeGameObjectFactory(GameObjectType::CAR);
    IGameObject *obj2 = makeGameObjectFactory(GameObjectType::BOAT);
    delete obj1;
    delete obj2;
}