//Given a 32-bit signed integer, reverse digits of an integer.
//Assume we are dealing with an environment which could only
//store integers within the 32-bit signed integer range: [−231,  231 − 1]

//For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
class Solution {
public:
    int reverse(int x) {
       
        int ans = 0;
        bool negative = x < 0;
        x = abs(x);
        
        while(x != 0){
            if(ans > (INT_MAX - (x%10))/10) return 0; // overflow
            ans = ans*10 + x%10;
            x/=10;
        }
        
        return negative? -ans : ans;
                
    }
};