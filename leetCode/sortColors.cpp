//Given an array with n objects colored red, white or blue, sort them in-place so that objects
//of the same color are adjacent, with the colors in the order red, white and blue.

//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//Could you come up with a one-pass algorithm using only constant space?
class Solution {
public:
    void sortColors(vector<int>& nums) {
     
//         //Counting Sort
//         map<int,int> mem;
        
//         for(int i = 0; i < nums.size(); i++)
//             mem[nums[i]]++;
        
//         int ptr;
//         for(ptr = 0; ptr < 3 && mem[ptr] == 0; ptr++);
        
//         for(int i = 0; i < nums.size(); i++){
//             nums[i] = ptr;
//             mem[ptr]--;
//             if(mem[ptr] == 0) ptr++;
//         }
        
        
        // One pass, O(n), space O(1)
        if(nums.size()==0) return;
        
        int first = 0, last = nums.size()-1;
        int actual = 0;
        
        while(actual <= last){
            if(nums[actual] == 0){
                swap(nums[actual],nums[first]);
                first++;
                actual++;
            }
            else if(nums[actual] == 2){
                swap(nums[actual],nums[last]);
                last--;
            }
            else actual++;
        }
    }
};