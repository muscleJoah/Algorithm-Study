class Solution {
public:
string longestPalindrome(string s) {
    
    
//https://leetcode.com/problems/longest-palindromic-substring/solution/    
//dp 배열 [i][j] 는 i번째 문자부터 j번째 문자까지가 palindrome 인지를 뜻한다.
// i ~ j 문자열이 palindrome 이면 i+1 ~ j-1 문자열이 palindrome 인것을 사용.
        
        
int length = s.size();
     
        
bool dp[length][length];
for(int i =0; i < length ; i++)
    for(int j =0; j <  length ; j++){
        if(i == j ) // i 와 j 같을 때, 즉 한개의 문자열은 무조건 palindrome 이다. 
            dp[i][j] = true;
        else
        dp[i][j] = false;
        
    }
int left,right;
int max=0;
        
for(int i=length-1; i>=0; i--)
     for(int j=i; j<length; j++){
           if(s[i] == s[j] && i != j){
             if(j-i == 1) //연속된 두 문자가 같으면 palindrome
                 dp[i][j]=true;
              else
                dp[i][j] = dp[i+1][j-1]; 
            }
          if(dp[i][j] && j-i>=max){
                max= j - i;
                right = j;  
                left = i;
                
            }
        }
    
    
    
    return s.substr(left,right-left+1);
}
    
};