#include <bits/stdc++.h>
using namespace std;
 
/* odredi da li je broj n prost */
bool prost(int n){
    if (n == 1) return false;
    for (int i = 2; i * i < n; i++){
        if (n % i==0) return false;
    }
    return true;
}

    

    

int main() {
    int n; cin >> n;
    if (prost(n))
        cout << "prost";
    else 
        cout << "nije prost";


    return 0;
}