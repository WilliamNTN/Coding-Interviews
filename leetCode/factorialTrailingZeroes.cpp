/*
Given an integer n, return the number of trailing zeroes in n!.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        
        int ans = 0;
        int factor = 1;
        int result = n/5;
        while(result > 0){
            ans += result;
            factor++;
            result = n/(pow(5,factor));
        }
        
        return ans;
    }
};