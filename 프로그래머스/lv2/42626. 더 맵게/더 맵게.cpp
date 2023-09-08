#include <bits/stdc++.h>

using namespace std;

long long a, b;

int solution(vector<int> scoville, int K) {

    priority_queue<int, vector<int>, greater<>> pq;
    
    for (int num : scoville) {
        pq.push(num);
    }
    
    int count = 0;
    bool isValid = false;
    
    while (pq.size()) {
        a = pq.top(); pq.pop();
    
        if (a >= K) {
            isValid = true;
            break;
        }
        
        if (pq.size()) {
            b = pq.top(); pq.pop();   
            pq.push(a + (b * 2));
            ++count;
        }
    }
    
    
    return isValid ? count : -1;
}