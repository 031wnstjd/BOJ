#include <bits/stdc++.h>

using namespace std;

int c_cnt, v_cnt, aeiou;
string s;

bool is_vowel(char& c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(true) {
		cin >> s;
		if(s == "end") break;
		aeiou = 0;
		c_cnt = 1;
		v_cnt = 1;
		bool is_possible = true;
		
		// 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
		for (char& c : s) {
			if(!is_vowel(c)) continue;
			aeiou = 1;
			break;
		}
		if(aeiou == 0) is_possible = false;
		
		// 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
		for (int i = 2; i < s.size(); i++) {
			if(is_vowel(s[i - 2]) && is_vowel(s[i - 1]) && is_vowel(s[i])) {
				is_possible = false;
				break;
			}
			if(!is_vowel(s[i - 2]) && !is_vowel(s[i - 1]) && !is_vowel(s[i])) {
			    is_possible = false;
				break;
			}
		}
		
		// 3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
		for (int i = 1; i < s.size(); i++) {
			if((s[i - 1] == s[i] && s[i] != 'e' && s[i] != 'o')) {
				is_possible = false;
				break;
			}
		}
		
		string ans = "<" + s + "> ";
		if(!is_possible) ans += "is not acceptable."; 
		else ans += "is acceptable.";
	
		cout << ans << '\n';
	}
	
	
	return 0;
}