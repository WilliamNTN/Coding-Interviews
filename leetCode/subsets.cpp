/*
Given a set of distinct integers, nums, return all possible subsets (the power set)
*/

class Solution {
public:
    
    void backtracking(int position,vector<int> nums,vector<int> soFar, vector<vector<int>>& ans){
        if(position == nums.size()){
            ans.push_back(soFar);
            return;
        }
        
        backtracking(position+1,nums,soFar,ans);
        soFar.push_back(nums[position]);
        backtracking(position+1,nums,soFar,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        backtracking(0,nums,vector<int>(),ans);
        return ans;
    }
};