#include <bits/stdc++.h> // task/1193
using namespace std;
/* Labyrinth Time limit: 1.00 s Memory limit: 512 MB
You are given a map of a labyrinth, and your task is to find a path from start to end. 
You can walk left, right, up and down.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.
Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description 
as a string consisting of characters L (left), R (right), U (up), and D (down). 
You can print any valid solution.
Constraints 1≤n,m≤1000
Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########
Output:
YES
9
LDDRRRRRU
*/


int main() {
	int brr, brk; cin >> brr >> brk;
	vector<vector<char>> lav(brr); // lavirint
	vector<vector<int>> put(brr);
	int ar, ak, br, bk; // pocetak i kraj, ared, akolona, bred, bkolona
	for (int r = 0; r < brr; r++) { // napravi lavirint
		lav[r] = vector<char>(brk); // resize
		put[r] = vector<int>(brk, -1); // -1 je neposećeno
		for (int k = 0; k < brk; k++) {
			cin >> lav[r][k]; // red i kolona
			if (lav[r][k] == 'A') { // start point
				ar = r; ak = k; } 
			else if (lav[r][k] == 'B') { // end point
				br = r; bk = k; } } }

	queue<tuple<int, int, int>> q; // trojka red, kolona i rb
	q.push(make_tuple(ar, ak, 0)); // start na stek, koordinate početka i rb = 0

	while (!q.empty()) { // dok red nije prazan...
		int r, k, rb; // trenutni red, kolina i rb
		tie(r, k, rb) = q.front(); q.pop();
		if (put[r][k] != -1) continue; // ako je posećeno odustani...
		// nije posećeno...
		put[r][k] = rb; // zapamti rb poteza

		if (r == br && k == bk) { // da li je kraj?
			cout << "YES" << endl << put[r][k] << endl;
			string res; // rešenje ide u string
			while (r != ar || k != ak) {
				if (r > 0 && put[r - 1][k] == rb - 1) {
					res.push_back('D');
					r--; 			} 
				else if (r < brr - 1 && put[r + 1][k] == rb - 1) {
					res.push_back('U');
					r++;			} 
				else if (k > 0 && put[r][k - 1] == rb - 1) {
					res.push_back('R');
					k--;			} 
				else {
					res.push_back('L');
					k++; 			}
				rb--; }
			reverse(res.begin(), res.end()); // okreni rešenje
			cout << res << endl; // ispis resenja
			return 0; }
		// nije kraj?
		if (r > 0 && lav[r - 1][k] != '#' && put[r - 1][k] == -1)
			q.push(make_tuple(r - 1, k, rb + 1)); // gore?
		if (r < brr - 1 && lav[r + 1][k] != '#' && put[r + 1][k] == -1)
			q.push(make_tuple(r + 1, k, rb + 1)); // dole?
		if (k > 0 && lav[r][k - 1] != '#' && put[r][k - 1] == -1)
			q.push(make_tuple(r, k - 1, rb + 1)); // levo
		if (k < brk - 1 && lav[r][k + 1] != '#' && put[r][k + 1] == -1)
			q.push(make_tuple(r, k + 1, rb + 1)); 	} // desno
	cout << "NO"; }