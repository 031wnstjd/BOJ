#include <bits/stdc++.h>
 
using namespace std;
 
bool cmp(vector<int> & a, vector<int> & b) {
    return a[1] < b[1];
}
 
int solution(vector<vector<int>> jobs) {
    
    sort(jobs.begin(), jobs.end(), cmp); // 실행 시간 기준 오름차순으로 정렬
    
    int curTime = 0;
    int sum = 0;
    int size = jobs.size();
    
    while (jobs.size()) {
        for (int i = 0; i < jobs.size(); ++i) {
            if (jobs[i][0] <= curTime) {
                curTime += jobs[i][1];
                sum += curTime - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }
            
            if (i == jobs.size() - 1) ++curTime;
        }
    }
    
    return sum / size;
}