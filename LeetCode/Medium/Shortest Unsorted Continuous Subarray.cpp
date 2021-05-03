//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> iVec = nums;
        sort(nums.begin(), nums.end());
        if(iVec == nums)
            return 0;
        
        int firstIndex;
        int lastIndex;
        for(int i = 0 ;i < nums.size(); i++)
            if(nums[i] != iVec[i])
            {
                firstIndex = i;
                break;
        
            }
        for(int i = nums.size()-1 ; i >=0 ; i--)
            if(nums[i] != iVec[i]){
                lastIndex =i;
                break;
                
            }
        
        
        return lastIndex - firstIndex + 1;
    }
};