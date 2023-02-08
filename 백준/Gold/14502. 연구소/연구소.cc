#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

#define MAX_N (10)

int N, M, board[MAX_N][MAX_N], tmp[MAX_N][MAX_N], ret;
vector<pair<int, int>> walls;
vector<pair<int, int>> virus;
int dr[4] = {0, 0, 1,-1};
int dc[4] = {1,-1, 0, 0};

void dfs(int r, int c) {
	for(int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= N || nc < 0 || nc >= M || tmp[nr][nc] != 0) continue;
		tmp[nr][nc] = 2;
		dfs(nr, nc);
	}
	return;
}

void comb(int start, int depth) {
	if(depth == 3) {
		copy(&board[0][0], &board[0][0] + MAX_N * MAX_N, &tmp[0][0]);
				
		for(auto pos : walls) tmp[pos.first][pos.second] = 1;
		for(auto pos : virus) dfs(pos.first, pos.second);				
		
		int cnt = 0;		
		for(int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(tmp[i][j] == 0) cnt++;
			}
		}
		
		ret = max(ret, cnt);
		
		return;
	}
	
	for (int i = start; i < N * M; i++) {
		int r = i / M;
		int c = i % M;
		if(board[r][c] != 0) continue;
		walls.push_back({r, c});
		comb(i + 1, depth + 1);
		walls.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if(board[i][j] == 2) virus.push_back({i, j});
		}
	}
	
	comb(0, 0);
	
	cout << ret << '\n';
	
	return 0;
}