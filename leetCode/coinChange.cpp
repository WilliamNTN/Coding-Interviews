/*
You are given coins of different denominations and a total amount of money amount
Write a function to compute the fewest number of coins that you need to make up that amount
If that amount of money cannot be made up by any combination of the coins, return -1.
*/

class Solution {
public:
    int **dp;
    int solve(int position, vector<int> coins, int amount){
        if(amount < 0) return 0x3f3f3f3f;
        if(amount == 0) return 0;
        if(position == coins.size()) return 0x3f3f3f3f;
        if(dp[position][amount] != -1)
            return dp[position][amount];
        int a,b,c;
        
        a = solve(position+1,coins,amount);
        b = solve(position,coins,amount-coins[position])+1;
        c = solve(position+1,coins,amount-coins[position])+1;
        
        return dp[position][amount] = min(a,min(b,c));
        
    }
    int coinChange(vector<int>& coins, int amount) {
        
        dp = (int**)malloc(sizeof(int*)*(coins.size() + 1));
        for(int i = 0; i <= coins.size(); i++)
            dp[i] = (int*)malloc(sizeof(int)*(amount+1));
        
        for(int i = 0; i < coins.size(); i++)
            for(int j = 0; j <= amount; j++)
                dp[i][j] = -1;
        
        int ans = solve(0,coins,amount);
        if(ans >= 0x3f3f3f3f)
            return -1;
        else
            return ans;
    }
};