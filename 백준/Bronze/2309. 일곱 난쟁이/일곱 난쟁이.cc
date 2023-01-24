#include <bits/stdc++.h>

#define N (9)
#define K (7)

using namespace std;

int arr[N];
vector<int> v;

void comb(int start, vector<int> v) {
	if(v.size() == K) {
		int sum = 0;
		for (int val : v) {
			sum += val;
		}
		
		if(sum == 100) {
			for (int val : v) cout << val << '\n';
			exit(0);
		}
		
		return;
	}

	for (int i = start + 1; i < N; i++) {
		v.push_back(arr[i]);
		comb(i, v);
		v.pop_back();
	}
}

int main() {
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+N);
	comb(-1, v);
	
	return 0;
}