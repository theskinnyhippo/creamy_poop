#include<iostream>
#include<cmath>
using namespace std;

class point{
    int x, y;

    public :
    point(){
        this->x=0;
        this->y=0;
    }
    point(int a, int b){
        this->x = a;
        this->y = b;
    }

    double distance(point p){
        double d = pow((pow(this->x - p.x, 2) + pow(this->y - p.y, 2)), 0.5);
        return d;
    }
};

int main(){
    point s1(3,4), s2;

    double dist = s1.distance(s2);
    cout << "The distance is " << dist << endl;
}