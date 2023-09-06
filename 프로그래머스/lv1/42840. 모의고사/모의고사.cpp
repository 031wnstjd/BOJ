#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int firstScore = 0;
    int secondScore = 0;
    int thirdScore = 0;
    
    vector<int> first  {1, 2, 3, 4, 5};
    vector<int> second {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third  {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); ++i) {
        int firstIdx = i % first.size();
        int secondIdx = i % second.size();
        int thirdIdx = i % third.size();
        
        if (answers[i] == first[firstIdx]) firstScore++;
        if (answers[i] == second[secondIdx]) secondScore++;
        if (answers[i] == third[thirdIdx]) thirdScore++;
    }
    
    int maxScore = max(firstScore, max(secondScore, thirdScore));
    
    if (firstScore == maxScore) answer.push_back(1); 
    if (secondScore == maxScore) answer.push_back(2);
    if (thirdScore == maxScore) answer.push_back(3);
    
    sort(answer.begin(), answer.end());
    
    return answer;
}