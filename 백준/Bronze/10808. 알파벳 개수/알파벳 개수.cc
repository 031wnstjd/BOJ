#include <bits/stdc++.h>
using namespace std;

#define N (26)

int alpha[N];
string s;

int main() {
	
	cin >> s;
	for (char c : s) {
		alpha[c - 'a']++;
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cout << alpha[i] << " "; 
	}
	
	
	return 0;
}