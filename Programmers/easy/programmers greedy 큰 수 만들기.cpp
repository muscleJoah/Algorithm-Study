#include <string>
#include <vector>
#include <stack>
#include <algorithm>

//https://programmers.co.kr/learn/courses/30/lessons/42883?language=cpp#


using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;
    int temp = k;

    for(int i = 0; i <number.length();i++)
    {
        while(!s.empty() && k>0) // 스택이 비지않고 빼기횟수가 1회이상일때 
        {
            if(s.top() < number[i]){
            s.pop(); // 새로 들어간 수가 먼저 들어간 수보다 크면 stack 의 top을 pop하고 새로들어간 수를 넣음 
            k--;
             }
            else
            break;    
        }
        s.push(number[i]); // 아닐경우 그냥 쑤셔박음.
     }
  
   
    
    while(s.size()!= (number.length()-temp))
          s.pop(); 
          //여기서 시간할애 엄청함
          // 그냥 그대로 넣어서 가장 큰수가 되는 경우도 있기때문에
          //빼기횟수 남은만큼 뒤에서 빼주어야함.
    int size= s.size();
    for(int i = 0;i < size;i++)
    {
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(),answer.end());
    
    return answer;
}