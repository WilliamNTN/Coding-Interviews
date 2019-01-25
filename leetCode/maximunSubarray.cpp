/*
Given an integer array nums, find the contiguous subarray
(containing at least one number) which has the largest sum and return its sum.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int ans = nums[0];
        int thisSum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            thisSum += nums[i];
            ans = max(ans,thisSum);
            if(thisSum < 0) thisSum = 0;
        }
        
        return ans;
    }
};