#include <bits/stdc++.h>
/*
	오른쪽 끝의 0의 개수 ==  10을 곱한 개수 == 2*5의 개수 == min(2의 개수, 5의 개수) == 5의 개수 (항상 5로 나눈 경우의 수가 더 작기 때문) 
*/
using namespace std;

typedef long long ll;

int TC, N;
ll cnt_two, cnt_five;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> N;
		cnt_two = 0; cnt_five = 0;
//		for(int i = 2; i <= N; i *= 2) cnt_two += (N / i);
		for (int j = 5; j <= N; j *= 5) cnt_five += (N / j);
//		cout << min(cnt_two, cnt_five) << '\n';
		cout << cnt_five << '\n'; 
	}
		
	return 0;
}