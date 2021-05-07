//https://programmers.co.kr/learn/courses/30/lessons/12981?language=cpp
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> game;
    bool end = false;
    int count = 0;
    for(int i =0;i < words.size(); i++){
        char lastChar;
        count ++;
        
        auto it = find(game.begin(), game.end(),words[i]);
        if(it != game.end())
        {
            
            end = true;
            break;
        }
        if(i != 0)
            if(lastChar != words[i][0]){
          
                end = true;
                break;
            }
        
        game.push_back(words[i]);
        int size = words[i].size();
        lastChar = words[i][size-1];
        cout << lastChar << endl;
    }
    if(!end)
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    
    
    int gameNum;
    int personNum;
    gameNum = (count-1) / n + 1;
    personNum = count % n;
    if(personNum == 0)
        personNum = n;
    
    answer.push_back(personNum);
    answer.push_back(gameNum);
    
    
    return answer;
}