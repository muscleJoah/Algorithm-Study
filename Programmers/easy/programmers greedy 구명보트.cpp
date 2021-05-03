#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42885?language=cpp


int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(),people.end());
    reverse(people.begin(),people.end()); //무게순대로 거꾸로 정렬
    int max = 0;  
    int min = people.size();
    
    while(max<min)
    {
        if(people[max] + people[min-1]<=limit)
            min--; //남아있는 것중 가장큰거랑 가장 작은거 더해서 리미트보다 작으면 둘다 태움
        max++;// 아닌경우엔 큰놈부터 계속 태움
        answer++;      
    }

    return answer;
}