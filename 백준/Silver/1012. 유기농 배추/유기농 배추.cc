#include <bits/stdc++.h>

using namespace std;

#define MAX_N (54)

int board[MAX_N][MAX_N], visited[MAX_N][MAX_N], T, N, M, K, r, c;

int dr[] = {0, 0,-1, 1};
int dc[] = {1,-1, 0, 0};

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
	
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				board[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		
		for (int i = 0; i < K; i++) {
			cin >> c >> r;
			board[r][c] = 1;
		}
				
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(board[i][j] && visited[i][j] == 0){
					dfs(i, j);	
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;
}