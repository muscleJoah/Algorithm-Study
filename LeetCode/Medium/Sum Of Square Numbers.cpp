//leetcode 633
class Solution {
public:
    bool judgeSquareSum(int c) {  
  for(int i=0 ;i <=sqrt(c) ; i++){
            
            int mod = c - i*i;
            double temp = sqrt(mod);
            if(temp == (int)temp)
                return true;
        }
        return false;

    }
};


