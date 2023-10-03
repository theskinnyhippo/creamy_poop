#include <cstdlib>
#include <iostream>
using namespace std;
#define rate 9

class SavingsAccount {

private:
    const int acno;
    int bal;
    string name;

public:
    SavingsAccount(int a) : acno(a) {
        name = gen_names();
        bal = random(100000, 1000);
    }

    int random(int u, int l) {
        int r = u - l + 1;
        r = (rand() % r) + l;
        return r;
    }

    void deposit(int taka) {  
        bal = bal + taka;
    }

    void withdraw(int taka) {
        bal = bal - taka;
    }

    int getAccountNumber() const {  
        return acno;
    }

    int getbal() const {  
        return bal;
    }

    string get_name(){
        return name;
    }

    string gen_names(){
    string a[6];

    a[0] = "Ashoke";
    a[1] = "Shyaam";
    a[2] = "Indra";
    a[3] = "Ashish";
    a[4] = "Chanchal";
    a[5] = "Hari";
    
    int k = random(5,0);
    string b[5];
    
    b[0] = " Kumar";
    b[1] = " Ranjan";
    b[2] = " Dev";
    b[3] = " Nandan";
    b[4] = " lal";
    
    int k1 = random(4,0);
    string c[6];
    
    c[0] = " Roy";
    c[1] = " Mondal";
    c[2] = " Singh";
    c[3] = " Shamanta";
    c[4] = " Banerjee";
    c[5] = " Mukherjee";
    c[6] = " Shukla";
    
    int k2 = random(6,0);
    string s = a[k] + b[k1] + c[k2];
    return s;
}




};

int main() {
    SavingsAccount* a[100];  
    int total_interest = 0;

    cout << "ac_no  |           Name          |  Balance  | interest ->  cuurent_balance" <<endl;
    cout << "==========================================================================="<< endl;
    for (int i = 0; i < 100; i++) {
            
            a[i] = new SavingsAccount(i + 165);
        
            cout << "00" << a[i]->getAccountNumber() <<"  |  " << a[i]->get_name() <<"\n                                    "<< a[i]->getbal() << "    |   " ;
            int interest = rate*a[i]->getbal()/100;

        total_interest +=interest;

        a[i]->deposit(interest);
        cout << interest << "      ----> " << a[i]->getbal() << endl;
    }

    cout << endl << "Total amount of interest paid to all accounts : " << total_interest <<endl;

    for (int i = 0; i < 100; i++) {
        delete a[i];
    }

    return 0;
}
