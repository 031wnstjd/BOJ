#include <bits/stdc++.h>
using namespace std;

int N, M, cnt, tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;	
	int nums[N];
	for (int i = 0; i < N; i++) cin >> nums[i];
	
	sort(nums, nums + N);
	
	int s = 0, e = N - 1;	
	while (s < e) {
		tmp = nums[s] + nums[e];
		if(tmp <= M) {
			if(tmp == M) cnt++;
			s++;
		}
		else e--;	
	}
	
	cout << cnt << '\n';
	
	return 0;
}