/*
Given a collection of distinct integers, return all possible permutations.
*/

class Solution {
public:
    
    
    void backtracking(int position,vector<int> nums, vector<vector<int>>& ans){
        if(position == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = position; i < nums.size(); i++){
            swap(nums[position],nums[i]);
            backtracking(position+1,nums,ans);
            swap(nums[position],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        backtracking(0,nums,ans);
        return ans;
    }
};