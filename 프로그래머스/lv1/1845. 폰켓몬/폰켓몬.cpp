#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    set<int> hs(nums.begin(), nums.end());
    
    return min(hs.size(), nums.size() / 2);
}