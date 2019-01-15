/*
Array oh integers, each represent the value at the house at that index
robbering two adjant houses alert the police

Given a list of non-negative integers representing the amount of money of each house
determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int* memo;
    int robR(vector<int> nums, int position){
        if(position  >= nums.size()) return 0;
        if(memo[position] != -1)
            return memo[position];
        
        int ans = -1;
        ans = max(ans,robR(nums,position+2)+nums[position]);
        ans = max(ans,robR(nums,position+1));
        
        return memo[position] = ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        memo = (int*)malloc(sizeof(int)*nums.size());
        for(int i = 0; i < nums.size(); i++)
            memo[i] = -1;
        
        return robR(nums,0);
    }
};