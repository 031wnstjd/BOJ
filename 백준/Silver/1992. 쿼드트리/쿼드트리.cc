#include <bits/stdc++.h>

using namespace std;

#define MAX_N (65)

int N;
char board[MAX_N][MAX_N];

string go(int r, int c, int size) {
	if(size == 1) return string(1, board[r][c]);
	char b = board[r][c];
	string ret = "";
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if(b != board[i][j]) {
				ret += '(';				
				ret += go(r, c, size / 2);
				ret += go(r, c + size / 2, size / 2);
				ret += go(r + size / 2, c, size / 2);
				ret += go(r + size / 2, c + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}
	return string(1, board[r][c]); 
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
			board[i][j] = s[j];
		}
	}	
	
	cout << go(0, 0, N) << '\n';
	
	return 0;
}