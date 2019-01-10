//Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray). 

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int ans = 1;
        int sofar = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                sofar++;
                ans = max(ans,sofar);
            }
            else
                sofar = 1;
        }
    return ans;
    }
    
};