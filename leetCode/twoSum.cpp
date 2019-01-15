/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        if(n==0) return ans;

        map<int,int> mem;

        for(int i = 0; i<n; i++){
            if(mem.find(target-nums[i]) != mem.end()){
                ans[0] = min(i,mem[target-nums[i]]);
                ans[1] = max(i,mem[target-nums[i]]);
                return ans;
            }
            mem[nums[i]] = i;
        }

        return ans;

    }
};