// Given a list of daily temperatures T, return a list such that, for each day in the input
//tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

//For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73]
//your output should be [1, 1, 4, 2, 1, 1, 0, 0].

//Note: The length of temperatures will be in the range [1, 30000]
//Each temperature will be an integer in the range [30, 100]. 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size());
        vector<int> next(101);
        
        for(int i = 30; i <= 100; i++)
            next[i] = -1;
        
        
        for(int i = T.size()-1; i>=0; i--){
            int val = T[i];
            int thisAns = -1;
            next[val] = i;
            for(int j = val+1; j <= 100; j++){
                if(next[j] != -1 && (next[j] < thisAns || thisAns == -1)){
                    thisAns = next[j];
                }
            }
            if(thisAns == -1){
                ans[i] = 0;
            }
            else{
                ans[i] = thisAns - i;
            }
        }
    return ans;
    }
    
};