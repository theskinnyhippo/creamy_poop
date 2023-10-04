#include<bits/stdc++.h>
using namespace std;

class Quadriatic{
    private :
        double a,b,c;

    public :
        Quadriatic() : a(0), b(0), c(0) {}
        Quadriatic(const double p,const double q, const double r) : a(p), b(q), c(r) {}
        Quadriatic(const Quadriatic &other) {
            Quadriatic(other.a, other.b, other.c);
        }
       ~Quadriatic(){}

        Quadriatic operator + (const Quadriatic &other) const {
            return Quadriatic(a+other.a, b+other.b, c+other.c);
        }

        Quadriatic operator >> 
};
