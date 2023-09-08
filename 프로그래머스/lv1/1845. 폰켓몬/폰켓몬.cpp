#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int targetCount = nums.size() / 2;
    set<int> hs;
    
    for (int num : nums) {
        hs.insert(num);
    }
    
    return hs.size() > targetCount ? targetCount : hs.size();
}