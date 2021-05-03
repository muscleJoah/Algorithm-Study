#include<iostream>
#include<string>


//시간초과...!!!!!!! DP로 풀어야한다...!!

class Solution {
public:
    
    bool isPalindrome(string s){
        int left = 0; int right = s.length()-1;
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;   
            }
            else
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string max = "";
        
        for(int i =0; i < s.length(); i++)
            for(int j = 1 ; j <= s.length() - i; j++){
                string sStr = s.substr(i,j);
                if(max.length() <= sStr.length())
                    if(isPalindrome(sStr))
                        max = sStr;
            }
        return max;
    }
};