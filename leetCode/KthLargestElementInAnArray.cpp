
//Find the kth largest element in an unsorted array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.


class Solution {
public:
    
    int partition(vector<int>& nums, int lo, int hi){
        if(lo >= hi) return lo;
        int pivot = nums[hi];
        int i = lo-1;
        for(int j = lo; j < hi; j++){
            if(nums[j] <= pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[hi]);
        return i+1;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        if(nums.size() == 0) return 0;
        
        int lo = 0, hi = nums.size()-1;
        int target = nums.size()-k;
        while(lo < hi){
            int p = partition(nums,lo,hi);
            if(p < target)
                lo = p+1;
            else if(p > target)
                hi = p-1;
            else break;
        }
        
        return nums[target];
    }
};