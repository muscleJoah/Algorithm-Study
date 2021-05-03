#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstring>
#include <set>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/64065?language=cpp
//1.문자열 나누기
//2. 이중벡터에 해당 문자열 int 형으로 치환해서 넣어주기.
//3. 이중벡터의 i번째 벡터와 i-1번재 벡터의 차집합으로 추출.

//stoi 를 포문안에서 빼고싶은데 그게 안되서 상당히 코드가 오래걸림..
//stoi를 빼거나 string 그자체로 비교하면 될 것 같은데 이것만 3시간 잡고있어서 너무 피로해서 여기서 stop.


bool compare(string s1 ,string s2)
{
    return s1.size() < s2.size();
}

vector<int> solution(string s) {
    
     vector<int> answer;
    vector<string> temp;
   
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
        
    } //모든문자열에서 특수문자 제거해주기.
    sort(temp.begin(),temp.end(),compare); //길이순서대로 정렬하면, 튜플순서대로 정렬이되겠죠~
    
   
    
    for(int i =0; i < temp.size();i++)
        if(temp[i][0]== ',')
            temp[i].erase(0,1); //첫글자에있는 콤마 지워주기.
    
  
   
    if(temp.size() == 1){
        answer.push_back(stoi(temp[0]));
        return answer;
    }
    vector<vector<int>> vVec(temp.size());
    
    for(int i =0 ; i < temp.size(); i++){
        string sTemp;
        for(int j=0 ;j <temp[i].length();j++){
            if(temp[i][j] >= '0' && temp[i][j] <= '9')
                sTemp += temp[i][j];
            if(temp[i][j] == ',' || j == temp[i].length()-1 ){
                
                vVec[i].push_back(stoi(sTemp));
                sTemp = "";
            }        
        }
    }
  
    for(int i = 0; i< vVec.size(); i++)// 차집합 구해주기.
    {
        if(i == 0){
            answer.push_back(vVec[0][0]);
            continue;
        }
        
       for(int j= 0 ; j<temp[i].length(); j++){
            if(find(vVec[i-1].begin(),vVec[i-1].end(),vVec[i][j])==vVec[i-1].end())
            {  
                answer.push_back(vVec[i][j]);
                break;
            }
        }
    } 
    
    return answer;    
}
