#include<iostream>
#include<array>
using namespace std;

class vector{
    int a[];
    vector(){
        this->a[0] = 0;
    }
    
    vector(int k){
        int s=0;
        while(k!=0){
            this->a[s] = k%10;
            k = k/10;
            s++;
        }
    }

    vector(vector &m){
        int n = m.a.size();

        for(int i=0; i<n; i++){
            this->a[i] = m.a[i];
        }
    }

    vector add(vector m){
        vector sum;
        sum.a = new int;
        if(this->size() > m.a.size()){
            sum.a[0] = 0;
            for(int i=0; i<m.a.size(); i++){
                sum.a[i] = sum.a[i] + (this->a[i] + m.a[i])%10;
                if((sum.a[i] + (this->a[i] + m.a[i])) >= 10){
                    sum.a[i+1] = 1;
                }else{
                    sum.a[i+1] = 0;
                }
            }            
            for(int i=m.a.size(); i<this->a.size(); i++){
                sum.a[i] = sum.a[i] + this->a[i];
                if(sum.a[i] + this->a[i] >= 10){
                    sum.a[i+1] = 1;
                }else{
                    sum.a[i+1] = 0;
                }
            }
        }else if(this->size() < m.a.size()){
            sum.a[0] = 0;
            for(int i=0; i<this->a.size(); i++){
                sum.a[i] = sum.a[i] + (this->a[i] + m.a[i])%10;
                if((sum.a[i] + (this->a[i] + m.a[i])) >= 10){
                    sum.a[i+1] = 1;
                }else{
                    sum.a[i+1] = 0;
                }
            }            
            for(int i=this->a.size(); i<m.a.size(); i++){
                sum.a[i] = sum.a[i] + m.a[i];
                if(sum.a[i] + m.a[i] >= 10){
                    sum.a[i+1] = 1;
                }else{
                    sum.a[i+1] = 0;
                }
            }
        }else{
            sum.a[0] = 0;
                for(int i=0; i<this->a.size(); i++){
                    sum.a[i] = sum.a[i] + (this->a[i] + m.a[i])%10;
                    if((sum.a[i] + (this->a[i] + m.a[i])) >= 10){
                        sum.a[i+1] = 1;
                    }else{
                        sum.a[i+1] = 0;
                    }
                }
            }
        return sum;
    }

    void display(){
        for(int i=this->a.size(); i>=0; i--){
            cout << this->a[i] ;
        }
    }
};
    

int main(){

}