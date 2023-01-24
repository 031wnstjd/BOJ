#include <bits/stdc++.h>

#define N (9)
#define K (7)

using namespace std;

int arr[N];

int main() {
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+N);
	
	do {
		int sum = 0;
		for (int i = 0; i < K; i++) sum += arr[i];
		if(sum == 100) break;
		
	} while(next_permutation(arr, arr + 9));
	
	for (int i = 0; i < K; i++) cout << arr[i] << '\n';	
	
	return 0;
}