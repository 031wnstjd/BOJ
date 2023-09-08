#include <bits/stdc++.h>

using namespace std;

#define MAXN 55
#define MAX 
#define INF  987654321

int d[MAXN];
vector<pair<int, int>> graph[MAXN];

int solution(int N, vector<vector<int>> road, int K) {
    
    fill(d, d + MAXN, INF);
    for (int i = 0; i < MAXN; ++i ) graph[i].clear();
    
    for (auto edge : road) {
        graph[edge[0]].push_back({edge[2], edge[1]}); // {dist, endNo}
        graph[edge[1]].push_back({edge[2], edge[0]}); // 양방향 할당
    }
    
    int startNo = 1;
    d[startNo] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({d[startNo], startNo});
    
    while (pq.size()) {
        pair<int, int> cur = pq.top(); pq.pop();
        
        if (d[cur.second] < cur.first) continue; // 이미 최단거리 정해졌으면 continue
        
        for (int i = 0; i < graph[cur.second].size(); ++i) {
            pair<int, int> nextNode = graph[cur.second][i];
            if (d[nextNode.second] > nextNode.first + d[cur.second]) {
                d[nextNode.second] = nextNode.first + d[cur.second];
                pq.push({nextNode.first, nextNode.second});
            }
        }
    }
    
    int count = 0;
    
    for (int val : d) {
        if (val <= K) ++count; 
    }

    return count;
}