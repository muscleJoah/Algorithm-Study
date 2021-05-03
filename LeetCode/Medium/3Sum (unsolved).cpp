class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
    
           vector<vector<int>> answer;
     
        for(int i =0;i < nums.size();i++){
            if(nums[i] == 0 && i != nums.size()-1)
                continue;
            else if(nums[i] != 0)
                break;
            
            else if(nums[i] == 0 && i == nums.size()-1){
            vector<int> temp;
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            answer.push_back(temp);
            return answer;
            }
        }
        
        if(nums.size() != 1){
        for(int i = 0;i < nums.size(); i++){
            int left = i+1;
            int right = nums.size() -1;
        
                
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            
            if(sum > 0)
                right--;
            
            else if(sum < 0)
                left ++;
            
            else if(sum == 0){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                answer.push_back(temp);
                left++;
                right--;
                }
             }
           }        
        
        sort(answer.begin(),answer.end());
        answer.erase(unique(answer.begin(), answer.end()),answer.end());
        
        return answer;}
        else
            return answer;
    }
};