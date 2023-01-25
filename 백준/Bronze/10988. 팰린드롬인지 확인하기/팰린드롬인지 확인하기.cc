#include <bits/stdc++.h>
using namespace std;

string s1;

int main() {
	cin >> s1;
	string copy = s1;
	reverse(s1.begin(), s1.end());
	
	if(s1.compare(copy) == 0) cout << 1;
	else cout << 0;
	
	return 0;
}