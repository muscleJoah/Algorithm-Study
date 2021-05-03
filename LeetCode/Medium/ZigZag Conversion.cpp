//https://leetcode.com/problems/zigzag-conversion/submissions/

class Solution {
public:
    string convert(string s, int numRows) {
     if(s.length() <= 2 || s.length() <= numRows || numRows == 1  )
         return s;
        
        string *sArr = new string[numRows];
        int len = s.length();
        int iZig = 2 * numRows - 2;
        string answer ="";
        
        for(int i =0 ; i < s.length(); i++){
            int iRem = i % iZig;
            if(iRem < numRows)
                sArr[iRem] += s[i];
           else
                sArr[numRows*2 - iRem -2] +=s[i];
        }    
        
        for(int i = 0 ; i < numRows ; i++)
            answer += sArr[i];
        return answer;
    }
};