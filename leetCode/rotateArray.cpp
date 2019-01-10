
//Given an array, rotate the array to the right by k steps, where k is non-negative.

class Solution {
public:
    
    void swap(vector<int>& nums, int start, int end){

        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            
            start++; end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0) return;
        if(k%nums.size() == 0) return;
        
        //First Solution: Time: O(n), Space: O(n)
        
        //vector<int> ans(nums.size());
        //k = k%nums.size();
        //int start = nums.size() - k;

        //for(int i = 0; i < nums.size(); i++){
        //ans[i] = nums[start];
        //start = (start+1)%nums.size();
        //}

        //for(int i = 0; i < nums.size(); i++)
        //nums[i] = ans[i];
        
        //Second Solution: Time: O(n*k), Space: O(1)
        
        // for(int i = 0; i < (k%nums.size()); i++){
        //     int last = nums[nums.size()-1];
        //     for(int i = nums.size()-1; i >=1; i--)
        //         nums[i] = nums[i-1];
        //     nums[0] = last;
        // } 
        
        //Best Solution: Time: O(n), Space: O(1)
        int n = nums.size();
        k = k % n;
        swap(nums,0,n-k-1);
        swap(nums,n-k,n-1);
        swap(nums,0,n-1);
    }
};