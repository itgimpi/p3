#include<bits/stdc++.h>
using namespace std; 

int main() {
    string s;

    string s1 ("Prvi string");
    string s2 (s1);
    string s3 (s1, 3, 6);

    string s4 = "Drugi string";
    string s5 ("Treci string", 6);

    string s6 (10, 'q'); string s7 (10, 64); // @
    string s8 (s1.begin()+1, s1.end()-1);
    s1[4] = '5';
    
    cout << s1 << endl; cout << s2 << endl; cout << s3 << endl;
    cout << s4 << endl; cout << s5 << endl;
    cout << s6 << endl; cout << s7 << endl;
    cout << s8 << endl; cout << s1 << endl;
    cout << s4[4] << s4.at(6) << endl;
    cout << s4.front() << s4.back() << endl;

    string str = "Danas je petak, sutra subota";
    str.erase(6, 3); cout << str << endl;
    str += ", preko ned."; cout << str << endl; 
    str.erase(str.begin()+7, str.end()-12); cout << str << endl;







 }