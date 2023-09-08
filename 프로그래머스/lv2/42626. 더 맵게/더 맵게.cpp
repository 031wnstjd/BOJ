#include <bits/stdc++.h>

using namespace std;

long long a, b;

int solution(vector<int> scoville, int K) {

    priority_queue<int, vector<int>, greater<>> pq(scoville.begin(), scoville.end());
    
    int count = 0;
    
    while (pq.top() < K) {
        if (pq.size() == 1) return -1;

        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        
        pq.push(a + (b * 2));
        ++count;
    }
    
    return count;
}