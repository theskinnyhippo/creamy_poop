#include<bits/stdc++.h>
using namespace std;


class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    friend ostream& operator <<(ostream& os, const Complex& c) {
        if (c.imag >= 0)
            os << c.real << " + " << c.imag << "i";
        else
            os << c.real << " - " << -c.imag << "i";
        return os;
    }
};

class Quadratic {
private:
    double a, b, c;

public:
    Quadratic(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}

    friend Quadratic operator+(const Quadratic& q1, const Quadratic& q2) {
        return Quadratic(q1.a + q2.a, q1.b + q2.b, q1.c + q2.c);
    }

    friend ostream& operator<<(ostream& os, const Quadratic& q) {
        os << q.a << "x^2";
        if (q.b >= 0)
            os << " + " << q.b << "x";
        else
            os << " - " << -q.b << "x";
        if (q.c >= 0)
            os << " + " << q.c;
        else
            os << " - " << -q.c;
        return os;
    }

    friend istream& operator>>(istream& is, Quadratic& q) {
        is >> q.a >> q.b >> q.c;
        return is;
    }

    double evaluate(double x) {
        return a * x * x + b * x + c;
    }

    pair<Complex, Complex> findRoots() {
        double discriminant = b * b - 4 * a * c;
        if (discriminant >= 0) {
            double sqrtDiscriminant = sqrt(discriminant);
            double root1 = (-b + sqrtDiscriminant) / (2 * a);
            double root2 = (-b - sqrtDiscriminant) / (2 * a);
            return {Complex(root1, 0), Complex(root2, 0)};
        } else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            return {Complex(realPart, imaginaryPart), Complex(realPart, -imaginaryPart)};
        }
    }
};

int main() {
    Quadratic q1, q2;
    cout << "Enter the coefficients of the first quadratic equation (a, b, c): ";
    cin >> q1;
    cout << "Enter the coefficients of the second quadratic equation (a, b, c): ";
    cin >> q2;

    Quadratic sum = q1 + q2;
    cout << "Sum of the two quadratic equations: " << sum << endl;

    double x;
    cout << "Enter a value for x to evaluate the first quadratic equation: ";
    cin >> x;
    cout << "Result of the evaluation: " << q1.evaluate(x) << endl;

    pair<Complex, Complex> roots = q1.findRoots();
    cout << "Roots of the first quadratic equation: " << roots.first << " and " << roots.second << endl;

    return 0;
}

