//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
//Find all unique triplets in the array which gives the sum of zero.

//The solution set must not contain duplicate triplets.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
       
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < n-2; i++){
            int target = -nums[i];
            int first = i+1;
            int last = n-1;
            
            while(first < last){
                if(nums[first] + nums[last] > target)
                    last--;
                else if(nums[first] + nums[last] < target)
                    first++;
                else{//solution
                    vector<int> sol(3,0);
                    sol[0] = nums[i];
                    sol[1] = nums[first];
                    sol[2] = nums[last];
                    
                    while(nums[first] == sol[1]) first++;
                    while(nums[last] == sol[2]) last--;
                    
                    ans.push_back(sol);
                }
            }
            
            while(i+1 < n-2 && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};