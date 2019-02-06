/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

*/

class Solution {
public:
    
    
   int binarySearchStart(vector<int> nums, int target){
       
       int ans = -1;
       int left = 0, right = nums.size() -1;
       
       while(left <= right){
           int middle = left + (right-left)/2;
           
           if(nums[middle] ==target) ans = middle;
           
           if(nums[middle] >= target) right = middle - 1;
           else left = middle + 1;
       }
       
       return ans;
   }
    int binarySearchEnd(vector<int> nums, int target){
       
       int ans = -1;
       int left = 0, right = nums.size() -1;
       
       while(left <= right){
           int middle = left + (right-left)/2;
           
           if(nums[middle] ==target) ans = middle;
           
           if(nums[middle] <= target) left = middle + 1;
           else right = middle - 1;
       }
       
       return ans;
   }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;         
        ans.push_back(binarySearchStart(nums,target));
        ans.push_back(binarySearchEnd(nums,target));
        
        return ans;
    
    }
};