#include <bits/stdc++.h>
using namespace std;

#define MAX_N (100000)

unordered_map<string, int> ht;
string names[MAX_N + 10];

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++) {
		cin >> names[i];
		ht.insert({names[i], i});
	}
	
	string tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		auto it = ht.find(tmp);
		if(it != ht.end()) cout << it->second << '\n';
		else cout << names[stoi(tmp)] << '\n';
	}
	
	return 0;
}