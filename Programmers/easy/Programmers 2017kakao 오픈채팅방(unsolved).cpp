#include <string>
#include <vector>
#include <iostream>
#include <sstream>



using namespace std;

class user{
    public:
    string action;
    string id;
    string nickname;
    user();
    user(string _action,string _id, string _nickname):action(_action),id(_id), nickname(_nickname)
    {};
    void changeNickname(string _nickname){
        this->nickname = _nickname;
    } 
    
};

vector<string> solution(vector<string> record) {
    
    vector<user> uVec;
    vector<string> vTemp;
    vector<string> answer;
    
    for(int i =0; i < record.size();i++){
    stringstream ss(record[i]);
    string token;
    while(ss>>token){
        vTemp.push_back(token);}
    uVec.push_back(user(vTemp[0],vTemp[1],vTemp[2]));
    vTemp.clear();
    }
    for(int i =0;i < uVec.size();i++){
        if(uVec[i].action == "Change" || uVec[i].action == "Enter"){
            for(int j = 0; j < i; j++){
                if(uVec[j].id == uVec[i].id)
                    uVec[j].changeNickname(uVec[i].nickname);
            }
        }     
    }
    string sTemp;
    
    for(auto e : uVec){
        
        if(e.action == "Enter"){
            sTemp = e.nickname + "님이 들어왔습니다.";
            answer.push_back(sTemp);
        }
        else if(e.action == "Leave"){
            sTemp = e.nickname + "님이 나갔습니다.";
            answer.push_back(sTemp);
        }
        sTemp = "";
    } 
    
    return answer;
}