#include<iostream>
using namespace std;
#include<string>

class BaseClass {
private:
    int i;
public:
    BaseClass(int i) {
        this->i = i + 1;
    }

    virtual int GetI() {
        return i;
    }
};

class SubClass :public BaseClass {
private:
    int i;
public:
    SubClass(int i) : BaseClass(i) {
        this->i = i + 100;
    }

    int GetI() override {
        return i;
    }
};

int main() {
    SubClass *sc = new SubClass(1);
    BaseClass *bc = (BaseClass*)sc;
    cout << sc->GetI() << " " << bc->GetI() << endl;
    system("pause");
    return 0;
}