#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17677?language=cpp
//1. 규칙에 의거하여 문자열로 자른뒤 벡터에 push
//2. 자른 문자열의 교집합과 합집합 구하기.

//이문제는 2시간이걸렸는데, 처음에 map 으로 구현하였는데 답이 계속 이상하게나와서
//당연히 교집합 구하기에 문제있다고 생각했는데
//구글링해서 std::set_intersection 함수 사용해서 구했는데 똑같이 나왔길래 
//문제를 다시 읽어보니 교집합은 처음부터 잘 구했는데 합집합을 중복제거없이 해버렸다.
//짜증난다 어려운문제는 아닌것같다.

vector<string> makeCharPair(string s) // 문자열 자르기 함수.
{
    vector<string> v;
    for(int i = 0 ; i < s.length()-1;i++){
        string temp = s.substr(i,2);
        if((isalpha(temp[0]) ==0) || (isalpha(temp[1])==0))
           continue;
        else{   
           transform(temp.begin(),temp.end(), temp.begin(),::tolower);        
           v.push_back(temp);    
        }
    }
    return v;
}
        
int solution(string str1, string str2) {
    double answer = 0;
    int mul = 65536;
    vector<string> vStr1 = makeCharPair(str1);
    vector<string> vStr2 = makeCharPair(str2);
    int inter = 0; int sUnion = 0; 
    int total = vStr1.size() + vStr2.size();
    
    for(auto element: vStr2)
        cout << element << endl;    
    
    sort(vStr1.begin(),vStr1.end());
    sort(vStr2.begin(),vStr2.end());
   
    vector<string> vInter(total);
    auto it = set_intersection(vStr1.begin(),vStr1.end(), vStr2.begin() , vStr2.end(),vInter.begin());
    vInter.erase(it, vInter.end()); // 정렬 및 교집합 구하기
    
    inter = vInter.size();
    sUnion = total - inter;
    if(vStr1.size() ==0 && vStr2.size() == 0)
        return mul;
    if(inter == 0)
        return 0;
    
    return (double)inter / sUnion * mul;
    
   
}