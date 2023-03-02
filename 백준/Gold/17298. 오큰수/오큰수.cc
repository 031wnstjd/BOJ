#include <bits/stdc++.h>

#define MAX_N 1000010

using namespace std;

stack<int> stk;
int N, a[MAX_N], ret[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		while(stk.size() && a[stk.top()] < a[i]) {
			ret[stk.top()] = a[i];
			stk.pop();
		}
		stk.push(i);
	}
	for (int i = 0; i < N; i++) cout << ret[i] << " ";
}