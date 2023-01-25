#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	getline(cin, s);
	
	for (int i = 0; i < s.size(); i++) {
		if('a' <= s[i] && s[i] <= 'z') s[i] = (s[i] + 13 <= 'z') ? s[i] + 13 : 'a' - 1 + (s[i] + 13) % 'z';
		if('A' <= s[i] && s[i] <= 'Z') s[i] = (s[i] + 13 <= 'Z') ? s[i] + 13 : 'A' - 1 + (s[i] + 13) % 'Z';	
	}	
	cout << s; 
	return 0;
} 