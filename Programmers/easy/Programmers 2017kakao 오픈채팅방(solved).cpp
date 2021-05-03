#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

//https://programmers.co.kr/learn/courses/30/lessons/42888
//이전에 썻던 알고리즘은 오류를 잡으니 시간이 10초이상걸려서 out 되버렸다.
//실패한 알고리즘이다. 형들이 알려준 알고리즘으로 풀으니 
//아주 깔끔하고 좋다.

using namespace std;
vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<vector<string>> sentence(record.size());
	map<string,string> user;
	//key - id, value - nickname
	for (int i = 0; i < record.size(); i++) {
		stringstream ss(record[i]);
        string token;
        while(ss >> token){
            sentence[i].push_back(token);
        }
		if (sentence[i][0]=="Enter" || sentence[i][0]=="Change")
			user[sentence[i][1]]=sentence[i][2]; 
            // 유저의 아이디를 해당 문장에 명시된 아이디로 바꿔준다.
		
	}
	for (auto e : sentence) {
		if (e[0] == "Enter") 
			answer.push_back(user[e[1]] + "님이 들어왔습니다.");
		else if(e[0] == "Leave") 
			answer.push_back(user[e[1]] + "님이 나갔습니다.");
	}
	return answer;
}