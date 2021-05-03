#include <string>
#include <vector>
#include <iostream>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/49993?language=cpp
//skill_tree[i]의 문자열에 skill 과 같은게 있으면 벡터에 추가해준뒤
//순서대로 안되어 있으면 잘못된 스킬트리로 간주하였음.
//3중 포문이라 매우 찝찝해서 다른 사람 풀이 봤는데 소름돋게 다들 똑같이풀었음.
//어렵지는 않았다. 근데 왜 한시간이 넘게 걸리지 나는 멍청한것같다. 

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int unOrder = 0;
    for(int i =0; i< skill_trees.size(); i++){
        vector<char> temp;
        for(int j =0; j < skill_trees[i].length(); j++){
            for(int a = 0; a < skill.length(); a++){
                if(skill[a] == skill_trees[i][j])
                    temp.push_back(skill[a]);
            }
        }
        
    
    for(int i =0; i < temp.size(); i++){
        if(temp[i]!= skill[i]){
            unOrder++;
            break;
        }
    }
   answer = skill_trees.size() - unOrder;
    }
    return answer;
    
    
}