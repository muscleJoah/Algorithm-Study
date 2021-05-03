#include <string>
#include <vector>
#include <iostream>
using namespace std;


//https://programmers.co.kr/learn/courses/30/lessons/17676?language=cpp

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> process; // <시작시간, 끝나는시간>
    for(int i = 0 ; i < lines.size(); i++)
    {
        int hour, minute, second, mSecond , pTime;
        hour = stoi(lines[i].substr(11,2)) * 3600 * 1000;
        minute = stoi(lines[i].substr(14,2)) * 60 * 1000;
        second = stoi(lines[i].substr(17,2)) * 1000;
        mSecond = stoi(lines[i].substr(20,3));
        pTime = stod(lines[i].substr(24,5))*1000;
        //시간을 ms 로 치환함.
        process.push_back(make_pair(hour+minute+second+mSecond+1-pTime,hour + minute+second+mSecond)); //시작시간 끝나는시간 쌍으로 벡터에 저장.
              
    
    }
    
    
    for(int i = 0;i < lines.size();i++)
    {
        int temp =0;//해당시간에 처리중인 량.
        for(int j = i; j < lines.size();j++)
        {
            if(process[j].first - 1000 < process[i].second)
                //j가 i 보다 늦게끝나거나 같은시간에 무조건 끝나므로
                //j의 시작시간 - 1초가 i의 끝나는시간 보다 작으면
                //해당시간에 처리중임.
           
            temp++;
        }
        if(answer < temp)
            answer = temp;
    }
    
    return answer;
}