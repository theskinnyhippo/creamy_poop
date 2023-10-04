#include<bits/stdc++.h>
using namespace std;

class Point{

    private :
        double x,y;

    public :
        Point() : x(0), y(0){}

        Point(const double a, const double b) : x(a), y(b) {}

        Point(const Point &p) {
            x = p.x;
            y = p.y;;
        }

        double operator - (Point p) const {
            double k;
            k = sqrt(pow(x-p.x,2)+pow(y-p.y,2));
            return k;
        }
};

int main(){
    Point a, b(4,4);
    Point c(b);
    cout << b - a << endl;
    cout << b-c << endl;
}
