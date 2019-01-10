//Say you have an array for which the ith element is the price of a given stock on day i.
//Max value with only one buy and sell

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;

        int ans = 0;
        
        int min = 0;
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[min] > prices[i])
                min = i;
            else
                ans = max(ans,prices[i] - prices[min]);
        }
        return ans;        
    }
};