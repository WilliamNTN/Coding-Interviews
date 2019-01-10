//Say you have an array for which the ith element is the price of a given stock on day i.

//Design an algorithm to find the maximum profit. You may complete as
//many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

//You may not engage in multiple transactions at the same time 
//(i.e., you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int ans = 0;
        
        for(int buy = 0; buy < prices.size()-1; buy++){
            if(prices[buy+1] > prices[buy]){
                int sell = buy+1;
                for(sell; sell < prices.size()-1 && prices[sell+1] > prices[sell]; sell++);
                if(prices[sell] > prices[buy]) ans += prices[sell] - prices[buy];
                buy = sell;
            }
        }
        return ans;      
    }
};