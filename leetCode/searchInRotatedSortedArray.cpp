/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

Search a value and return index
in Logn

*/

class Solution {
public:
    
    int findPivot(vector<int> nums){
        
        
        int left = 0, right = nums.size()-1;
        
        while(left <= right){
            int middle = left + (right-left)/2;
            if(middle < nums.size()-1 && nums[middle] > nums[middle + 1]) return middle;
            if(middle == nums.size()-1 && nums[middle] < nums[middle-1]) return middle;
            
            if(nums[middle] >= nums[0]) left = middle + 1;
            else right = middle - 1;
            
        }
        
        return -1;
    }
        
    int binarySearch(vector<int> nums, int left, int right, int target){
        
        while(left <= right){
            int middle = left + (right-left)/2;
            
            if(nums[middle] == target) return middle;
            if(nums[middle] > target) right = middle - 1;
            else left = middle + 1;
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        int pivot = findPivot(nums);
        if(pivot == -1)
            return binarySearch(nums,0,nums.size()-1,target);
        if(target >= nums[0]){
            return binarySearch(nums,0,pivot,target);
        }
        return binarySearch(nums,pivot+1,nums.size()-1,target);
    }
};