#include <bits/stdc++.h>

using namespace std;

int TC, N;
unordered_map<string, int> ht;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> TC;
	for (int testCase = 0; testCase < TC; testCase++) {
		cin >> N;
				
		string name, category;
		for (int i = 0; i < N; i++) {
			cin >> name >> category;
			auto it = ht.find(category);
			if (it != ht.end()) it->second += 1;
			else ht.insert({category, 2});
		} 		
		int res = 1;
		for (auto it : ht) res *= it.second;
		cout << res - 1 << '\n';
		ht.clear(); 
	}
	
	return 0;
}