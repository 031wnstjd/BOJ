#include <bits/stdc++.h>

using namespace std;

vector<string> v;

int N; 
string s;

bool cmp(string a, string b) {
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			if('0' <= s[i] && s[i] <= '9') tmp += s[i];		
			if(i == s.size() - 1 || '0' > s[i] || s[i] > '9') {
				if(tmp.size()) {
					while(tmp[0] == '0') tmp.erase(tmp.begin());
					if(tmp.size() == 0) tmp = "0";
					v.push_back(tmp);
					tmp = "";
				}
			}
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for (string ret : v) cout << ret << '\n';
	
	return 0;
}