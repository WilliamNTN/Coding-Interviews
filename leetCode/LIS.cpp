class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        /*if(nums.size() == 0) return 0;
        int ans = 0;
        vector<int> lis(nums.size(),1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i] && lis[j]+1 > lis[i]){
                    lis[i] = lis[j]+1;
                }
            }
            ans = max(ans,lis[i]);
        }
        
        return ans;*/
        
        // O(nlogn)
        if(nums.size() == 0) return 0;
        map<int,int> tails;
        tails[1] = nums[0];
        int maxTail = 1;
        int greaterLis = 1;
        for(int i = 1; i < nums.size(); i++){
            int value = nums[i];    
            
            int left = 1, right = maxTail;
            int ans = 0;
            while(left <= right){
                int middle = left + (right-left)/2;
                if(tails[middle] < value){
                    ans = middle;
                    left = middle + 1;
                }
                else{
                    right = middle - 1;
                }
            }
            tails[ans+1] = value;
            maxTail = max(maxTail,ans+1);
        }
        
        return maxTail;
    }
};