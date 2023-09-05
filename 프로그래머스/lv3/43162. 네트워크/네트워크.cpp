#include <bits/stdc++.h>

using namespace std;

#define MAX_N 205

bool visited[MAX_N];
bool isValid;

void find(int r, vector<vector<int>> computers) {        
    for (int i = 0; i < computers.size(); ++i) {
        if (visited[i] || computers[r][i] == 0) continue;
        visited[r] = true;
        isValid = true;
        find(i, computers);
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int count = 0;
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < computers.size(); ++i) {
        isValid = false;
        find(i, computers);
        if (isValid) count++;
    }
        
    return count;
}