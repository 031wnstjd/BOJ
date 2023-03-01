#include <bits/stdc++.h>

#define MAX_N 10010
#define MAX_M 100010

using namespace std;

vector<int> computers[MAX_N];
bool visited[MAX_N];
int N, M;

int dfs(int here) {
	int ret = 1;
	visited[here] = true;
	
	for (int there : computers[here]) {
		if(visited[there]) continue;
		ret += dfs(there);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from;
		int to;
		cin >> from >> to;
		computers[to].push_back(from);
	}
	
	int mx = 0;
	vector<int> ret;
	for(int i = 1; i <= N; i++) {
		fill(&visited[0], &visited[0]+MAX_N, false);
		int tmp = dfs(i);
		if(mx < tmp) {
			mx = tmp;
			ret.clear();
			ret.push_back(i);	
		}
		else if(mx == tmp) ret.push_back(i);
	}
	
	sort(ret.begin(), ret.end());
	
	for (int a : ret) cout << a << " ";
}