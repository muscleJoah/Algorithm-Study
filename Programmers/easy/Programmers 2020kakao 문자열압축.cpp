#include <string>
#include <vector>
using namespace std;


//https://programmers.co.kr/learn/courses/30/lessons/60057

int solution(string s) {
    int answer = s.length();

    if (s.length() == 1)
        answer = 1;
    for (int i = 1; i <= s.length() / 2; i++)
    {

        string first = s.substr(0, i); //첫번째로 자른 문자열
        string compare; // 비교대상
        string temp; // 비어잇는 string
        int count = 1; // 연속된 문자열이 몇개나 있는지
        for (int j = i; j < s.length(); j += i)
        {
            compare = s.substr(j, i);
            if (first == compare)count++;
            else
            {
                if (count > 1)temp += to_string(count);
                temp += first; //비어있는 string 변수에 넣어준다.
                first = s.substr(j, i); //연속된 문자열 뒤에 문자열부터 시작함..
                count = 1;
            }
        }
        if (count > 1) temp += to_string(count);
        temp += first;
        if (answer > temp.length())
            answer = temp.length();
    }

    return answer;
}