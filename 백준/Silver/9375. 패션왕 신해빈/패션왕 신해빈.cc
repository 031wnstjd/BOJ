#include <bits/stdc++.h>

using namespace std;

int tc, N;
string name, category;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> tc;
	while(tc--) {
		map<string, int> _map;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> name >> category;
			_map[category]++;
		} 		
		int res = 1;
		for (auto it : _map) res *= (it.second + 1);
		res--;
		cout << res << '\n';
	}
	
	return 0;
}