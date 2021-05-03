#include <vector>
#include <iostream>
#include <string>
using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/43162?language=cpp
//생각보다 구현이 어려워서 솔루션보고 다시풀어봄.
//dfs 인건 알았는데 어떻게 dfs를 써야할지 모르겠어서 못풀었다. 
//다같이 풀어보면 좋을 것 같다 .
//네크워크가 떨어져있는지 확인을 목표로 알고리즘을 구현함.
//코드만 보면 쉬워보이는데 생각하는게 굉장히 어렵다고 ㅎ
 
bool dfs(vector<vector<int>>& vCom, int n) {
    if (!vCom[n][n]) 
        return false; //순회한곳이라면 탈출.
    
    vCom[n][n] = 0; // 순회한 부분은 0으로 바꿔준다.
    
    for (int i = 0; i < vCom.size(); i++) 
        if (vCom[n][i])
            dfs(vCom, i); //연결된 노드가있으면 dfs다시불러옴.
    
    return true;
}
 
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) 
        if (computers[i][i] != 0 && dfs(computers, i))
            answer++; 
    
    return answer;
}