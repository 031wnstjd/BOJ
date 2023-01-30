#include <bits/stdc++.h>

using namespace std;

#define MAX_N (54)

int board[MAX_N][MAX_N], visited[MAX_N][MAX_N], t, N, M, K, r, c, ret;

int dr[4] = {0, 0,-1, 1};
int dc[4] = {1,-1, 0, 0};

void dfs(int r, int c) {
	visited[r][c] = 1;
	for(int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == 0 || visited[nr][nc]) continue;
		dfs(nr, nc);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--) {
		fill(&board[0][0], &board[0][0] + MAX_N * MAX_N, 0);
		fill(&visited[0][0], &visited[0][0] + MAX_N * MAX_N, 0);
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> c >> r;
			board[r][c] = 1;
		}
				
		ret = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(board[i][j] && !visited[i][j]){
					dfs(i, j);	
					ret++;
				}
			}
		}
		cout << ret << '\n';
	}
	
	return 0;
}