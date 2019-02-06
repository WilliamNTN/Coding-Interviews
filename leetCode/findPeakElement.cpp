class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int n = nums.size();
        int left = 0, right = n -1;
        
        while(left <= right){
            int middle = left + (right-left)/2;
            long long a = -LONG_MAX;
            long long b = -LONG_MAX;
            int value = nums[middle];
            if(middle > 0) a = nums[middle-1];
            if(middle < n-1) b = nums[middle + 1];
            
            if(a < value && value > b ){
                return middle;
            }
           if(a < value && value < b){
               left = middle + 1;
           }
           else
               right = middle - 1;
        }
        return -1;
    }
};