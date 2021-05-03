//https://leetcode.com/problems/largest-multiple-of-three/

//3의배수 판정법.

// 모든 자릿수를 더했을대 3으로 나누어떨어지면됨.


//if total % 3 == 0 -> do nothing
//total % 3 == 1 -> reduce 1,4,7  or reduce 2,5,8 twice
//total % 3 == 2  -> reduce 2,5,8 or reduce 1,4,7 twice
class Solution {
public:
       string largestMultipleOfThree(vector<int>& digits) {
        int iSum = 0;
        int arr[10] = {0}; 
        int mods[6] = {2,5,8,1,4,7};
        string answer = "";
        for(auto e: digits)
        {   arr[e]++;
            iSum += e;
        }
        if(iSum == 0 && arr[0] != 0)
            return "0";
        if(iSum %3 == 0 && iSum != 0 )
        {
            sort(digits.begin(), digits.end());
            reverse(digits.begin(), digits.end());
            for(auto e : digits)
                answer += to_string(e);
            return answer;
        }
        
        if(iSum %3 == 1){
            if(arr[1]!=0){arr[1]--; goto print;}
            if(arr[4]!=0){arr[4]--; goto print;}   
            if(arr[7]!=0){arr[7]--; goto print;}   
        }
       
            for(auto e: mods)
            while(iSum % 3 !=0 && arr[e] != 0 )
            {
                arr[e]--;
                iSum -= e;
            }
        print:
        for(int i= 9; i > -1 ; i--){
            while(arr[i] > 0) {answer += to_string(i); arr[i]--;}
        }
    
        return answer;
    }
};