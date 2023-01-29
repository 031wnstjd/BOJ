#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	while(scanf("%d", &n) != EOF) {
		long long a = 1;
		int ret = 1;
		while(1) {
			if(a % n == 0) break;
			a = (a * 10) + 1;
			a %= n; // overflow 방지 
			ret++;
		}
		cout << ret << '\n';
	}	
	return 0;
}