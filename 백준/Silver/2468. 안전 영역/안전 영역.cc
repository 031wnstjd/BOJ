#include <bits/stdc++.h>

using namespace std;

#define MAX_N (104)

int N, board[MAX_N][MAX_N], visited[MAX_N][MAX_N], cnt, max_cnt, max_height;
int dr[] = {0, 0,-1, 1};
int dc[] = {1,-1, 0, 0};

void dfs(int r, int c, int h) {
	visited[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || board[nr][nc] <= h) continue;
		dfs(nr, nc, h);	
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			max_height = max_height < board[i][j] ? board[i][j] : max_height;
		}
	}
		
	for (int h = 0; h <= max_height; h++) {
		fill(&visited[0][0], &visited[0][0] + MAX_N * MAX_N, 0);
		cnt = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(visited[i][j] || board[i][j] <= h) continue;
				dfs(i, j, h);
				cnt++;
			}
		}
		max_cnt = max_cnt < cnt ? cnt : max_cnt;
	}
	
	cout << max_cnt << '\n';
	
	return 0;
}