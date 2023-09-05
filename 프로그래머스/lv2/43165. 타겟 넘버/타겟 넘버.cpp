#include <string>
#include <vector>

using namespace std;
int count;

void getCount(vector<int> numbers, int target, int sum, int idx) {
    if (idx == numbers.size()) {
        if (target == sum) {
            count += 1;
            return;
        } else {
            return;
        }
    }
    
    getCount(numbers, target, sum + numbers[idx], idx + 1);
    getCount(numbers, target, sum - numbers[idx], idx + 1);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    count = 0;
    
    getCount(numbers, target, 0, 0);
    
    return count;
}

