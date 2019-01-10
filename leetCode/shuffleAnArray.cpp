//Shuffle a set of numbers without duplicates. 

class Solution {
public:
    vector<int> original;
    Solution(vector<int> nums) {
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans(original);
        
        for(int i = 0; i<original.size(); i++){
            int pos = rand()%original.size();
            swap(ans[i],ans[pos]);
        };
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */