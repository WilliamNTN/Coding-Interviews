/*
Implement int sqrt(int x).

Compute and return the square root of x
where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal
digits are truncated and only the integer part of the result is returned.
*/

class Solution {
public:
    int mySqrt(int x) {
       
        int l = 0, r = x;
        int ans = 0;
        
        while(l <= r){
            double middle = l+ (int)(r-l)/2;
            if(middle * middle <= x){
                ans = middle; l = middle + 1;
            }else{
                r = middle-1;
            }
        }
        
        return ans;
    }
};