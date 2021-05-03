//leetcode 152
//브루트포스 ->>> O(n^2) 될리가없음. 고로 생각조차 하지 않겟따.
//나의 코딩실력 향상에 브루트포스는 걸림돌이 될뿐이다.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        
        vector<int> vMax;
        int firstNum = nums[0];
        int iMax = nums[0];
        int iMin = nums[0];        
        for(int i = 1; i < nums.size(); i++)
        {
            int minjun = iMax;
            iMax = max(max(nums[i] * iMax , nums[i] * iMin),nums[i]);
            iMin = min(min(nums[i] * minjun, nums[i] * iMin),nums[i]);
            vMax.push_back(iMax);

        }
        sort(vMax.begin(), vMax.end(), greater<int>());
        return max(vMax[0],firstNum);
    }
};