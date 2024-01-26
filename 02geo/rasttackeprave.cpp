#include <bits/stdc++.h> // by MDJ

using namespace std;

struct tacka{ //struktura tacka
    double x,y;
};

double vektorskiproizvod(const tacka &t1, const tacka &t2){
    return (t1.x * t2.y) - (t1.y * t2.x); //vektorski proizvod
    
}

int main()
{
    tacka A, B, P; cin >> A.x >> A.y >> B.x >> B.y >> P.x >> P.y;
    //TRANSLACIJA TACKE A U KOORDINATNI POCETAK
    B.x-=A.x; 
    B.y-=A.y; 
    P.x-=A.x;
    P.y-=A.y;
    
    cout << fixed << showpoint << setprecision(4) << abs(vektorskiproizvod(B, P))/sqrt(B.x * B.x + B.y * B.y); //intenzitet vektora, ne moze da bude negativan zato uzimamo abs
    
    
    return 0;
}