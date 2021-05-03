#include <string>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/43165
//매우간단한문제, 1을 더하거나 빼거나 두가지의 경우만 생각해주면됨.
//DFS 로 풀었음. 승우형이 비슷한 문제 풀어봤길래 생각나서 다시풀어본문제.

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int count)
{
    if(count == numbers.size()){
        if(sum == target )
             answer++;
             return;
    }
    dfs(numbers, target, sum + numbers[count], count+1 );
    dfs(numbers, target, sum - numbers[count], count+1 );
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target,0, 0);
    return answer;
}