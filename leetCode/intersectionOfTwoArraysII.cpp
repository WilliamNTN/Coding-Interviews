//Given two arrays, write a function to compute their intersection.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*
        First Solution. Time: O(n+m), Space(min(n,m));
        
        if(nums2.size() < nums1.size())  // keep nums1 as smaller vector 
            return intersect(nums2, nums1);

        vector<int> ans;
        if(nums1.size() == 0 || nums2.size() == 0)
            return ans;

        unordered_map<int,int> us;

        for(int i = 0; i < nums1.size(); i++){
            us[nums1[i] ]++;
        }

        for(int i = 0; i < nums2.size(); i++){
            if(us.find(nums2[i]) != us.end() && us[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                us[nums2[i]]--;
            }
        }
        
        return ans;
        */
        
        //sorted arrays
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int p1 = 0, p2 = 0;
        vector<int> ans;

        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1] == nums2[p2]){
                ans.push_back(nums1[p1]);
                p1++; p2++;
            }
            else if(nums1[p1] > nums2[p2]){
                p2++;
            }
            else{
                p1++;
            }
        }

        return ans;

    }
};