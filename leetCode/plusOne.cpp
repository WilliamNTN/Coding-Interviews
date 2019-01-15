/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list
and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> ans(digits.begin(),digits.end());
        if(digits.size()==0) return ans;

        int pointer = digits.size()-1;
        ans[pointer] = (ans[pointer]+1)%10;  // if 9 -> 0

        while(pointer > 0 && ans[pointer] == 0){
            pointer--;
            ans[pointer] = (ans[pointer]+1)%10;
        }

        // pointer = 0
        // ans[pointer] != 0

        // digits[pointer] != 0   -> return
        if(ans[pointer] != 0) return ans;

        //pointer == 0 && ans[0] == 0
        ans.insert(ans.begin(),1);
        return ans;
    }
};