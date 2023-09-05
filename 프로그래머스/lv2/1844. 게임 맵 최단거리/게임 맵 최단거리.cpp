#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

const int dr[] = {0, 0,-1, 1};
const int dc[] = {1,-1, 0, 0};

bool visited[MAXN][MAXN];

int solution(vector<vector<int>> maps)
{
    const int N = maps.size();
    const int M = maps[0].size();
    
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    visited[0][0] = true;
    
    while (q.size()) {
        pair<int, int> cur = q.front(); q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            
            if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] || maps[nr][nc] == 0) continue;
            
            q.push({nr, nc});
            visited[nr][nc] = true;
            maps[nr][nc] = maps[cur.first][cur.second] + 1;
        }
    }
    
    return maps[N - 1][M - 1] != 1 ? maps[N - 1][M - 1] : -1;
}