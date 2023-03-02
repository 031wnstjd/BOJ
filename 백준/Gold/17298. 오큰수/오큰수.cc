#include <bits/stdc++.h>

#define MAX_N 1000010

using namespace std;

stack<pair<int, int>> stk;
vector<pair<int, int>> v;
int N, val;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> val;
		while(stk.size() && stk.top().second < val) {
			v.push_back({stk.top().first, val}); 
			stk.pop();
		}
		stk.push({i, val});
	}
	while(stk.size()) {
		v.push_back({stk.top().first, -1});
		stk.pop();
	}
	sort(v.begin(), v.end());
	for (auto ret : v) cout << ret.second << " ";
}