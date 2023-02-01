#include <bits/stdc++.h>

using namespace std;

struct RANGE {
	int s, e;
};

int N, M, J, pos, s, e, ret; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> J;
	
	RANGE range = {1, M};
	
	for(int t = 0; t < J; t++) {
		cin >> pos;
		s = range.s;
		e = range.e;
		if(s <= pos && pos <= e) continue;
		
		while(pos < s) {
			if(range.s == pos) break;
			range.s--; range.e--;
			ret++;
		}
		
		while(e < pos) {
			if(range.e == pos) break;
			range.s++; range.e++;			
			ret++;
		}
	}
	
	cout << ret << '\n';
	
	return 0;
}

