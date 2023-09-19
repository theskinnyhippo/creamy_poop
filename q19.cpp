#include<iostream>
using namespace std;

class rec{
    double l, b;

    public :
    rec(){
        this->l=0;
        this->b=0;
    }
    rec(double a, double b){
        if(a>b){
            this->l = a;
            this->b = b;
        }else{
            this->b = a;
            this->l = b;
        }
    }

    double area(void){
        double area = this->l*this->b;
        return area;
    }
};


int main(){
    rec A(21.99,66.15), B(2,3.1);

    double a = A.area();
    double b = B.area();

    cout << "the two areas are : " << a <<" "<< b << endl;
}