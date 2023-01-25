#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int cnt[101];

int main() {
	cin >> a >> b >> c;
	int s, e;
	for (int i = 0; i < 3; i++) {
		cin >> s >> e;
		for (int j = s; j < e; j++) cnt[j]++; // 마지막 인덱스 미포함 
	}
	
	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		if(cnt[i] == 0) continue;
		else if(cnt[i] == 1) sum += cnt[i] * a;
		else if(cnt[i] == 2) sum += cnt[i] * b;
		else sum += cnt[i] * c;
	}
	
	cout << sum;
	
	return 0;
}