#include <bits/stdc++.h>

using namespace std;

#define MAX_N (65)

int N, board[MAX_N][MAX_N];
vector<char> ret;

void dfs(int rs, int cs, int re, int ce, int size) {
	int cnt = 0;
	for (int i = rs; i < re; i++) {
		for (int j = cs; j < ce; j++) {
			if(board[i][j] == 1) cnt++;
		}
	}
	
	if(cnt == size) {
		ret.push_back('1');
		return;
	}
	
	if(cnt == 0) {
		ret.push_back('0');
		return;
	}
	
	int rm = (rs + re) / 2;
	int cm = (cs + ce) / 2;
	
	ret.push_back('(');

	dfs(rs, cs, rm, cm, size/4);
	dfs(rs, cm, rm, ce, size/4);
	dfs(rm, cs, re, cm, size/4);
	dfs(rm, cm, re, ce, size/4);
		
	ret.push_back(')');
	
	return; 
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	string s;
	for(int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			board[i][j] = s[j] - '0';
		}
	}	
	
	dfs(0, 0, N, N, N*N);
	
	for(char c : ret) cout << c;
	
	return 0;
}