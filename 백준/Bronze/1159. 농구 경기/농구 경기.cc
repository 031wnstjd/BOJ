#include <bits/stdc++.h>
using namespace std;

string s;
int N;
int cnt[26];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		cnt[s[0] - 'a']++;
	}	
	
	bool flag = false;
	for (int i = 0; i < 26; i++) {
		if(cnt[i] >= 5) {
			cout << (char)(i + 'a');
			flag = true;
		}
	}
	
	if(!flag) cout << "PREDAJA";	
		
	return 0;
}