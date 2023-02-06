#include <iostream>
#include <stack> 

using namespace std;

string s;
char tmp;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	while(true) {
		getline(cin, s);
		stack<char> stk;
		if(s[0] == '.') break;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']') continue;	
			if(stk.size() && stk.top() == '(' && s[i] == ')' ) stk.pop();
			else if(stk.size() && stk.top() == '[' && s[i] == ']') stk.pop();
			else stk.push(s[i]);
		}
		if(stk.size()) cout << "no" << '\n';
		else cout << "yes" << '\n';
	}
	return 0;
} 