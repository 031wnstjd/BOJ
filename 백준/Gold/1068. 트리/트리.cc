#include <bits/stdc++.h>

using namespace std;

#define MAX_N 55

vector<int> adj[MAX_N];
int N, rNode, root; 

int dfs(int here) {
	int ret = 0;
	int child = 0;
	for (int there : adj[here]) {
		if(there == rNode) continue;
		ret += dfs(there);
		child++;
	}
	if(child == 0) return 1;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if(tmp == -1) root = i;
		else adj[tmp].push_back(i);
	}	
	cin >> rNode;
	if(rNode == root) {
		cout << 0 << '\n';
		return 0;
	}
	cout << dfs(root) << '\n';
}