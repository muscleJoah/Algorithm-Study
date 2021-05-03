#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstring>
using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/64065?language=cpp
//안되는 이유알것같음 다시해볼래.
//짱구굴려보니까 안되는 케이스를 생각할수 있었음.
//이거 되는경우도잇고 안되는 경우도있는데 여튼 1시간넘게걸려서 짠거 아까워서
//걍 같이 올림. ㅋㅋ

bool compare(string s1 ,string s2)
{
    return s1.size() < s2.size();
}

vector<int> solution(string s) {
    
    vector<string> temp;
    vector<string> vTemp;
    char *ch = new char[s.size()-1];
    strcpy(ch, s.c_str()); // string s 를 char 형태로 치환.
   
    char *ptr = strtok(ch, "}"); // 집합별로 자르려고 } 로 나누었음.
    while (ptr != nullptr) {
        stringstream ss;
        string str;
        ss << ptr;
        ss >> str;
        temp.push_back(str);
        ptr = strtok(nullptr,"}");
    }
    for(int i = 0; i < temp.size(); i++){
        temp[i].erase(remove(temp[i].begin(),temp[i].end(),'{'),temp[i].end());
        temp[i].erase(remove(temp[i].begin(),temp[i].end(),','),temp[i].end());
    } //모든문자열에서 특수문자 제거해주기.
    sort(temp.begin(),temp.end(),compare); //길이순서대로 정렬하면, 튜플순서대로 정렬이되겠죠~
    
    for(auto e : temp) 
        cout << e << endl; //잘 분리되는지 확인용 출력문.
  
    
    //여기 밑에서부터 봐주면 될 것같음
    for(int i= 0; i < temp.size(); i++){
        string tStr = temp[i];
        if(i > 0){
            for(int j=0;j<vTemp.size();j++){
                if(tStr.find(vTemp[j])<tStr.length()) //find 함수가 찾았을떄
                    tStr.erase(tStr.find(vTemp[j]), vTemp[j].size());       
            }
             vTemp.push_back(tStr);
        }
        else{
            vTemp.push_back(tStr);
           
    }
    }
    vector<int> answer;
    for(auto element : vTemp)
    answer.push_back(stoi(element));
    
    
   
    
    return answer;

    
}