//Given an array consisting of n integers, find the contiguous subarray of given
//length k that has the maximum average value. And you need to output the maximum average value.

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double curSum = 0;
        
        for(int i = 0; i < k; i++){
            curSum += nums[i];
        }
       
        double curAvg = curSum/double(k);
        double maxAvg = curAvg;
        for(int i = k; i < nums.size(); i++){
            curSum -= nums[i-k];
            curSum += nums[i];
            curAvg = curSum/double(k);
            if(curAvg > maxAvg) maxAvg = curAvg;
        }
        
        return maxAvg;
    }
};