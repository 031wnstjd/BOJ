#include <bits/stdc++.h>

using namespace std;

#define MAX_N (100)

int N, M, K, visited[MAX_N][MAX_N], r, c;
int c1, r1, c2, r2;
int dr[] = {0, 0,-1, 1};
int dc[] = {1,-1, 0, 0};
vector<int> v;

int bfs(int a, int b) {
	queue<pair<int, int>> que;
	que.push({a, b});
	visited[a][b] = 1;
	int cnt = 0;
	while(que.size()) {
		tie(r, c) = que.front(); que.pop();
		cnt++;
		for(int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) continue;
			que.push({nr, nc});
			visited[nr][nc] = 1;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		cin >> c1 >> r1 >> c2 >> r2;
		for (int i = r1; i < r2; i++) {
			for (int j = c1; j < c2; j++) {
				visited[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(visited[i][j]) continue;
			v.push_back(bfs(i ,j));
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size() << '\n';
	for(int ret : v) cout << ret << " ";
	
	return 0;
}