#include <bits/stdc++.h>
using namespace std;

int N, cnt;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		stack<char> stk;
		for (char c : s) {
			if(stk.size() && stk.top() == c) stk.pop();	
			else stk.push(c);
		}
		if(stk.size() == 0) cnt++;
	}
	
	cout << cnt << '\n';
	
	return 0;
}