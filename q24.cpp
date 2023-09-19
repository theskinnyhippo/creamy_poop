#include <iostream>
using namespace std;

class MyClass {
private:
    mutable int data; 

public:
    MyClass(int value) : data(value) {}

    int getValue() const {
        data = 10;
        return data;
    }
};

int main() {
    const MyClass obj(42);
    cout << "Value: " << obj.getValue() << endl;
    return 0;
}
