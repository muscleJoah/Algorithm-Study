//https://programmers.co.kr/learn/courses/30/lessons/12987?language=cpp
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;


int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(),greater<int>());
    sort(B.begin(), B.end(),greater<int>());
    int Acount = 0;
    int Bcount = 0;
    for(int i =0;i < A.size(); i++ ){
        if(A[Acount] < B[Bcount])
        {
            answer++;
            Bcount++;
           
        }
        Acount ++;
     
    }
    
    
    
    return answer;
}