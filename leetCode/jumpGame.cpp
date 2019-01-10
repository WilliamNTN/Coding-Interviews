
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//Each element in the array represents your maximum jump length at that position.
//Determine if you are able to reach the last index

class Solution {
public:
    vector<int> memory;
    
    bool canJump(vector<int>&nums,int position){
        if(position >= nums.size()-1) return true;
        
        if(memory[position] != -1){
            return memory[position] == 1;
        }
        
        bool ans = false;
        for(int i = nums[position]; i>=1; i--){
            ans |= canJump(nums,position+i);
        }
        
        memory[position] = ans? 1: 0;
        return ans;
    }
    
    bool canJump(vector<int>& nums){ 
        if(nums.size() <= 1) return true;
        
        memory = vector<int>(nums.size(),-1);
         
        return canJump(nums,0);
    }
    
};