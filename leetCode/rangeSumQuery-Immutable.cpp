//Given an integer array nums, find the sum of the elements between
//indices i and j (i ≤ j), inclusive.

class NumArray {
public:
    vector<int> cumSum;
    NumArray(vector<int> nums) {
        if(nums.size() == 0) return;
        cumSum.reserve(nums.size());
        cumSum[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            cumSum[i] = cumSum[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return cumSum[j] - (i == 0?0:cumSum[i-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */