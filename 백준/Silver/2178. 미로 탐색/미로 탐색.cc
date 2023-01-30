#include <bits/stdc++.h>

using namespace std;

int N, M;
int dr[] = {0, 0,-1, 1};
int dc[] = {1,-1, 0, 0}; 

int main() {
	cin >> N >> M;	
	int board[N][M];
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			board[i][j] = s[j] - '0';
		}
	}
	
	queue<pair<int, int>> que;
	bool visited[N][M];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) visited[i][j] = false;
	}
	
	que.push({0, 0});
	visited[0][0] = true;
	int cnt = 0;
	
	while(int size = que.size()) {
		cnt++;
		while(size--) {
			auto cur = que.front();
			que.pop();
			
			if(cur.first == N - 1 && cur.second == M - 1) {
				cout << cnt << '\n';
				return 0;
			}
			
			for (int i = 0; i < 4; i++) {
				int nr = cur.first + dr[i];
				int nc = cur.second + dc[i];
				
				if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || board[nr][nc] == 0) continue;
				
				que.push({nr, nc});
				visited[nr][nc] = true;
			}
		}
	}
	
	return 0;
}