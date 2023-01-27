#include <bits/stdc++.h>

using namespace std;

int cnt[200], cnt_odd;
string s, ret;
char odd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	for (char c : s) cnt[c]++;
	for (int i = 'Z'; i >= 'A'; i--) {
		if(cnt[i]) {
			if(cnt[i] & 1) {
				odd = char(i);
				cnt_odd++;
				cnt[i]--;	
			}
			if(cnt_odd >= 2) break;
			for (int j = 0; j < cnt[i]; j += 2) {
				ret = char(i) + ret;
				ret += char(i);
			}
		}	
	}
	
	if(odd) ret.insert(ret.begin() + ret.size() / 2, odd);
	
	if(cnt_odd >= 2) cout << "I'm Sorry Hansoo" << '\n';
	else cout << ret << '\n';
		
	return 0;
}

