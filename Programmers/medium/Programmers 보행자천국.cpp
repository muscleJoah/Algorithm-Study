//https://programmers.co.kr/learn/courses/30/lessons/1832

#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요. 
int solution(int m, int n, vector<vector<int>> city_map) {
    
    int **down = new int*[m+1];
    int **right = new int*[m+1];
    for(int i = 0;i < m+1 ;i ++)
    {
        down[i] = new int[n+1];
        right[i] = new int[n+1];
    }
    for(int i =0;i  < m+1; i++)
        for(int j =0;j < n+1 ; j++)
            down[i][j] = right[i][j] = 0;
  
    
    int iCase;
    for(int i = 1; i < m+1 ; i ++)
        for(int j= 1; j < n+1 ; j++){
            iCase = city_map[i-1][j-1];
            if(i==1 && j ==1)
            {
                right[i][j] =1;
                down[i][j] =1 ;
            }
            switch(iCase){
                case 0: 
            {
                down[i][j] += (down[i-1][j] + right[i][j-1]) % MOD;
                right[i][j] += (down[i-1][j] + right[i][j-1]) % MOD;
                break;
            }
                case 1: 
            {
                down[i][j] = 0;
                right[i][j] = 0;
                break;
            }
                case 2:
            {
                down[i][j] = down[i-1][j] % MOD;   
                right[i][j] = right[i][j-1] % MOD;
                break;
            }                 
          }
       } 
    int answer = 0;
    answer = (right[m][n-1]+down[m-1][n]) % MOD;
    
    
    return answer;
}