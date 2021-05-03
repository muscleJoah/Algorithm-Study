#include <string>
#include <vector>
#include <iostream>

using namespace std;
int sToSec(string s){
    string hour = s.substr(0,2);
    string minute = s.substr(3,2);
    string second = s.substr(6,2);
    return stoi(hour)*3600 + stoi(minute) * 60 + stoi(second);
}


string solution(string play_time, string adv_time, vector<string> logs) {
    
    
    int adv[360000] = {0};
    int iPlaytime = sToSec(play_time);
    int iAdvtime = sToSec(adv_time);
    int sum = 0; 
    int max = 0;
    int index = 0;
   
    
    string answer = "";
    for(int i =0;i < logs.size(); i++)
    {
        int start = sToSec(logs[i].substr(0,8));
        int end = sToSec(logs[i].substr(9,8));
        for(int j = start ; j< end ; j++ )
            adv[j]++;
    }
    
    
    for(int i =1;i < iPlaytime ;i ++)
        adv[i] += adv[i-1];
    
    for(int i = 0;i < iPlaytime - iAdvtime ; i++){
        sum = adv[i + iAdvtime] - adv[i];
        if(sum > max){
            max = sum;
            index = i+1;
        }
    }
    cout << index << endl;
    
    int second = index % 60; index= index / 60;
    int minute = index % 60; index = index / 60;
    int hour = index;
    
    if(hour < 10)
        answer += "0";
    answer += to_string(hour);
    
    answer += ":";
    if(minute < 10)
        answer += "0";
    answer += to_string(minute);
    
    answer += ":";
    if(second < 10)
        answer += "0";
    answer +=  to_string(second);
    
    return answer;
}