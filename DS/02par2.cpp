#include <iostream>
#include <utility>
using namespace std;
/*Date su koordinate tri tačke trougla. Odredi koordinate njegovog težišta.*/
int main() {
    pair<double, double> a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    pair<double, double> t;
    t.first = (a.first + b.first + c.first) / 3.0; // po x...
    t.second = (a.second + b.second + c.second) / 3.0; // po y...

    cout << t.first << " " << t.second << endl;
    return 0; }
