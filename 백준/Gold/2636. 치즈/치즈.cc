#include <bits/stdc++.h>

#define MAX_N 101

using namespace std;

int dr[4] = {0, 0,-1, 1};
int dc[4] = {1,-1, 0, 0};

int board[MAX_N][MAX_N], N, M, cnt;
bool visited[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if(board[i][j] == 1) cnt++;
		}
	}
	
	int left = 0;
	int t = 0;
	while (cnt > 0) {
		queue<pair<int, int>> que;
		memset(visited, 0, sizeof(visited));
		
		que.push({0, 0});
		visited[0][0] = true;
		left = cnt;
		t++;
		
		while(que.size()) {
			pair<int, int> cur = que.front(); que.pop();
			
			int r = cur.first;
			int c = cur.second;
			
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				
				if(nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) continue;
				if(board[nr][nc] == 1) {
					board[nr][nc] = 0;
					visited[nr][nc] = true;
					cnt--;
					continue;
				}
				
				que.push({nr, nc});
				visited[nr][nc] = true; 
			}
		}
	}
	
	cout << t << '\n' << left;
	
	return 0;
}