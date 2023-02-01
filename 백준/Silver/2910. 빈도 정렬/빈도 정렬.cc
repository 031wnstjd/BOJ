#include <bits/stdc++.h>

using namespace std;

#define MAX_N (1004)

struct NUMINFO {
	int num, cnt, order;
};

struct COMP {
	bool operator()(NUMINFO &a, NUMINFO &b) {
		if(a.cnt == b.cnt) return a.order > b.order;
		return a.cnt < b.cnt;
	}
};

priority_queue<NUMINFO, vector<NUMINFO>, COMP> pq; 
map<int, NUMINFO> mp;
int N, C, tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	
	cin >> N >> C;
	int order = 1;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		mp[tmp].num = tmp;
		if(mp[tmp].order == 0) mp[tmp].order = order++;
		mp[tmp].cnt++;
	}
	
	for(auto a : mp) pq.push(a.second);	
	
	while(pq.size()){
		NUMINFO ret = pq.top(); pq.pop();
		for(int i = 0; i < ret.cnt; i++) cout << ret.num << " ";
	}
	
	return 0;
}