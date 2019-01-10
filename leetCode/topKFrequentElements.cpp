//Given a non-empty array of integers, return the k most frequent elements.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     
        
        //Time: O(n), Space: O(n)
        int n = nums.size();
        vector<int> ans;
        if(n == 0) return ans;
        
        unordered_map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++){ // O(n)
            mp[nums[i]]++;
        }
        
        vector<vector<int>> buckets(n+1);
        
        for(auto p: mp){
            buckets[p.second].push_back(p.first); // O(n)
        }
        
        for(int i = buckets.size()-1; i>=0 && ans.size() < k; i--){ // O(n)
            for(int j = 0; j < buckets[i].size(); j++){
                ans.push_back(buckets[i][j]);
                if(ans.size() == k) break;
            }
        }
        
        return ans;
    }
};