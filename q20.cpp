#include<iostream>
#include<cmath>
using namespace std;

class device{
    double x,y,r;
    
    public :
    device(){
        this->x = 0;
        this->y = 0;
        this->r = 0;
    }

    device(double a, double b, double c){
        this->x = a;
        this->y = b;
        this->r = c;
    }

    device (device &m){
        this->x = m.x;
        this->y = m.y;
        this->r = m.r;
    }

    int neighbour(device p){
        double d = pow((pow(this->x - p.x, 2) + pow(this->y - p.y, 2)), 0.5);
        if(this->r >= d){
            return 1;
        }else{
            return 0;
        }
    }

    void legitification(device n){
        if(this->x == n.x && this->y == n.y){
            double a, b;
            cout << endl <<"Invalid POSITIONING !" <<endl << "new position.... \nx y : ";
            cin >> a >> b;
            this->x = a;
            this->y = b;
            legitification(n);
        }
    }
};

/*void legitification(device m, device n){
        if(m.x == n.x && m.y == n.y){
            double a, b;
            cout << endl <<"Invalid POSITIONING !" <<endl << "new position.... \nx y : ";
            cin >> a >> b;
            m.x = a;
            m.y = b;
            legitification(m,n);
        }
    }*/



int main(){
    int k;
    cout << "Enter number of devices : " << endl;
    cin >> k;
    device* a = new device[k];
    for(int i=0; i<k; i++){
        double xc, yc, range;
        cout << endl << "data about device " << i << endl << " x y range : ";
        cin >> xc >> yc >> range;
        a[i] = device(xc, yc ,range);

        for(int j=0; j<i; j++){
            a[i].legitification(a[j]);
        }
    }
     
    int l, j=0, count = 0;
    cout << "device u wanna find neightbour of : " << endl;
    cin >> l;
    cout << "neightbours of device " << l << "..." << endl;
    while(j<k){
        if(j!=l){
            if(a[l].neighbour(a[j])){
                cout << "device " << j << endl;
                count++;
            }
        }
        j++;
    }
    if(count == 0){
        cout << "NO neighbour found!" << endl;
    }
}