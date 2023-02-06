#include <iostream>
#include <stack>

using namespace std;

string s;
int N;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		stack<char> stk;
		cin >> s;
		for(int j = 0; j < s.size(); j++) {
			char tmp = s[j];
			if(stk.size() && stk.top() == '(' && tmp == ')') stk.pop();
			else stk.push(tmp);
		}
		if(stk.size()) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}	
	return 0;	
}