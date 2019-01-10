//Given an array of integers, find if the array contains any duplicates.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;
        int n = nums.size();
        
        //First Solution: Time O(n), Space O(n)
//         set<int> st;
        
//         for(int i = 0; i<n; i++){
            
//             if(st.find(nums[i])!=st.end()) return true;
//             st.insert(nums[i]);
//         }
        
//         return false;
        
        
        //Second Solution: Time: O(nlogn), Space: O(1)
        
        sort(nums.begin(),nums.end());
        
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};