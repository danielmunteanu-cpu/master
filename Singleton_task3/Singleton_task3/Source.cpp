#include <iostream>
#include <memory>
using namespace std;

// Singleton
class Singleton {
private:
    Singleton() {}

public:
    static Singleton& getInstance() {
        static Singleton obj;
        return obj;
    }
};
//Abstract factory
class Button {
public:
    virtual void show() = 0;
};
class WinButton : public Button {
    void show () override {
        cout << "Windows Button";
    }
};
class MacButton : public Button {
    void show() override {
        cout << "Mac Button";
    }
};
class Factory {
public:
    virtual Button* createButton() = 0;
};
class WinFactory : public Factory {
    public:
        Button* createButton() override{
            return new WinButton();
        }
};
class MacFactory : public Factory {
    public:
        Button* createButton() override {
            return new MacButton();
        }
};
int main() 
{
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    cout << &s1 << " " << &s2<<endl;
    Factory* factory = new MacFactory();
    Button* b = factory->createButton();
    b->show();
}