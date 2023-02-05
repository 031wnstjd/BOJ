#include <bits/stdc++.h>

using namespace std;

#define MAX_H (104)

char cloud[MAX_H][MAX_H];
int ret[MAX_H][MAX_H];

int H, W, val;
bool flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> H >> W;
	
	for (int i = 0; i < H; i++) {
		flag = false;
		for (int j = 0; j < W; j++) {
			cin >> cloud[i][j];
			if(cloud[i][j] == 'c') {
				flag = true;
				val = 0;
				ret[i][j] = val++;
			}
			else {
				if(flag) {
					ret[i][j] = val++;					
				} 
				else {
					ret[i][j] = -1;		
				}
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << ret[i][j] << " ";	
		}
		cout << '\n';
	}
		
	return 0;
}