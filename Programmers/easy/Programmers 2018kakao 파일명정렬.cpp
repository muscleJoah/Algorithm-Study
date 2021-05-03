#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17686?language=cpp
//1. 헤드, 넘버, INDEX로분할함
//2. 작성한 CLASS 형식으로 파일명을 객체화시킴
//3. 비교함수 사용을 통한 정렬

//리뷰 댓글로 남겨주셈 
//원래 클래스 파일네임으로 안짜고 이중벡터로 0 인덱스 에는 head, 1 인덱스에는 number, 2index 에는 files의 INDEX 를 넣었었는데
//그렇게 돌렸을때 3.xx ms 이런식으로나오던게
//클래스 만들어서 돌리니까 0.xx ms 로 나옴.

class fileName{
    public:
    string head;
    int number;
    int index;
    fileName(string _head, int _number, int _index) : head(_head), number(_number), index(_index)
    {};
    };
        


bool compare(fileName a, fileName b){
    if(a.head == b.head) {
        if(a.number == b.number)
            return a.index < b.index;
        return a.number < b.number ;
    }
    else 
        return a.head<b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fileName> BHI; 
   
    for(int i = 0; i < files.size(); i++){
        string head;
        string number;
        for(int j = 0; j<files[i].length();){
            int numberCount = 0;
            while(!(files[i].at(j) >= '0' && files[i].at(j) <= '9') ){                              
                head += tolower(files[i].at(j));
                //대문자와 소문자 같은 단어로 취급하기때문에 모두 소문자로 만들어주었음.
                j++;
                continue; //HEAD 만들기
             }
            while(j < files[i].size() && files[i].at(j) >= '0' && files[i].at(j)<='9' && numberCount != 5)//NUMBER는 최대 다섯개까지만 허용.
            {
                ++numberCount;
                number += files[i].at(j);
                j++;
                //NUMBER 만들기.
            }
            fileName f(head, stoi(number),i);
            BHI.push_back(f);
            break;
        }
    }
    sort(BHI.begin(),BHI.end(),compare);//비교함수를 통한 정렬
    
    for(auto file : BHI)
          answer.push_back(files[file.index]);
    
        
    return answer;
}