class Solution {
public:
    bool canJump(vector<int>& nums) {
     int max = 0;
        for(int i =0; i < nums.size(); i ++)
        {
            if(i > max ) return false;
            if(i + nums[i] >= nums.size()-1) return true;
            max = max > i + nums[i] ? max : i+nums[i];
        }
        return false;
    }
};