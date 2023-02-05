#include <bits/stdc++.h>

using namespace std;

int N, minute, sec, team, pre_min, pre_sec;
int a_score, b_score, a_time, b_time;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &team);
		scanf("%2d:%2d", &minute, &sec);
		
		if(a_score > b_score) a_time += ((minute - pre_min) * 60 + (sec - pre_sec));
		else if(a_score < b_score) b_time += ((minute - pre_min) * 60 + (sec - pre_sec));
		
		if(team == 1) a_score++;
		else b_score++;
			
		pre_min = minute;
		pre_sec = sec;		
	}

	if(a_score > b_score) a_time += ((48 - minute) * 60 + (0 - sec));
	else if(a_score < b_score) b_time += ((48 - minute) * 60 + (0 - sec));
	
	printf("%02d:%02d\n", a_time / 60, a_time % 60);
	printf("%02d:%02d\n", b_time / 60, b_time % 60);
		
	return 0;
}