//Given an array consists of non-negative integers
//your task is to count the number of triplets chosen from
//the array that can make triangles if we take them as side
//lengths of a triangle.

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int ans = 0;
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size()-2; i++){
            for(int j = i+1; j < nums.size()-1; j++){
                int limit = nums[i] + nums[j];
                int position = lower_bound(nums.begin(),nums.end(),limit) - nums.begin();
                if(position >= nums.size()) position = nums.size()-1;
                if(position < j) position = j;
                while(nums[position] >= limit && position > j) position--;
                
                ans += position-j;
            }
        }
                
        return ans;
    }
};