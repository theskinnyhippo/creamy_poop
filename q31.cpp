#include<bits/stdc++.h>
using namespace std;

class Complex{
    private :
        double x, y;

    public :
        Complex() : x(0), y(0){}
        Complex(const double a, const double b) : x(a), y(b) {}
        Complex(const Complex &C){
            Complex(C.x, C.y);
        }
       ~Complex(){}

        double mag_sq() const {
            double m = ((x*x) + (y*y));
            return m;
        }

        Complex operator + (const Complex &m) const {
            return Complex (x+m.x, y+m.y);
        }

        Complex operator - (const Complex &m) const {
            return Complex (x-m.x, y-m.y);
        }

        Complex operator = (const Complex &C) const {
            return Complex(C.x, C.y);
        }

        Complex operator * (const Complex &m) const {
            return Complex(x*m.x - y*m.y, x*m.y + y*m.x);
        }

        Complex operator / (const Complex &m) const {
            double mag = m.mag_sq();
            return Complex((x*m.x + y*m.y)/mag, (y*m.x - x*m.y)/mag);
        }

        void display(){
            cout << x << " + " << y << "i " << endl;
        }
};

int main(){
    Complex a(1,2), b(3,4), c(5,5);
    Complex d = a / b;

    d.display();
}
