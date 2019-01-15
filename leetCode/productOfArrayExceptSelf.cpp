//Given an array nums of n integers where n > 1,  return an array output such that output[i]
//is equal to the product of all the elements of nums except nums[i].

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
        vector<int> ans(nums.size());
        if(nums.size() == 0) return ans;
        
        ans[0] = 1;
        
        for(int i = 1; i < nums.size(); i++){
            ans[i] = nums[i-1] * ans[i-1];
        }
        
        int right = 1;
        
        for(int i = nums.size()-1; i>=0; i--){
            ans[i] = ans[i] * right;
            right = right * nums[i];
        }
        
        return ans;
        
    }
};