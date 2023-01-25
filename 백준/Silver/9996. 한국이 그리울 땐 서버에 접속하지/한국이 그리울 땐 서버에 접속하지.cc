#include <bits/stdc++.h>
using namespace std;

int N;
string s, temp, pre, suf;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
	cin >> N;
	cin >> s;
	
	int pos = s.find('*');
	pre = s.substr(0, pos);
	suf = s.substr(pos + 1, s.size());
	
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if(pre.size() + suf.size() > temp.size() || pre != temp.substr(0, pre.size()) || suf != temp.substr(temp.size() - suf.size())) cout << "NE" << '\n'; 
		else cout << "DA" <<'\n';
	}
	
	return 0;
}