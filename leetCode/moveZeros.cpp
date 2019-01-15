/*Given an array nums, write a function to move all 0's to the end of it
while maintaining the relative order of the non-zero elements.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;

        int pZero = 0;
        while(nums[pZero] != 0) pZero++; //pZero is at first zero
        int i = pZero+1;
        while(pZero < n && i < n){
            if(nums[i] != 0){
                nums[pZero] = nums[i];
                nums[i] = 0;    
                while(pZero < n && nums[pZero] != 0)
                    pZero++;
            }
            i = max(i+1,pZero+1);
        }
        return;
    }
    
};