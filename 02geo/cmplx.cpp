#include <iostream>
#include <complex> // kompleksni brojevi
using namespace std;



int main() {
    complex<int>z0 (1,2);
    cout << z0.real() << ' ' << z0.imag() << endl;

    complex<int>z1 (3,4);
    cout << z1.real() << ' ' << z1.imag() << endl;
    
    //complex<double>z2 (3.14,2.71);
    //cout << z2.real() << ' ' << z2.imag() << endl;   

    complex<int>z3 = z0 + z1; 
    cout << z3.real() << ' ' << z3.imag() << endl;

    complex<int>z4 = z0 * z1; 
    cout << z4.real() << ' ' << z4.imag() << endl;    

    complex<double>ojler (4.0, 3.0);
    cout << abs( ojler ) << ' ' << arg( ojler ) << endl;
    cout << abs( ojler ) << ' ' << arg( ojler )*360.0/6.28 << endl;
    // rad : 2pi = ste : 360 -> st = rad*360 / 2 pi

    complex<double>ojler1 (1.0, 1.0);
    cout << abs( ojler1 ) << ' ' << arg( ojler1 )*180.0/acos(-1) << endl;


    return 0;
}