
//Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> ans(nums.size());
        
        sort(nums.begin(),nums.end());
        
        int leftPointer = (nums.size()-1)/2;
        int rightPointer = (nums.size()-1);
        
        for(int i = 1; i <= nums.size(); i++){
            if(i&1 == 1) // odd
                ans[i-1] = nums[leftPointer--];
            else
                ans[i-1] = nums[rightPointer--];
        }
        
        for(int i = 0; i < nums.size(); i++)
            nums[i] = ans[i];
    }
};