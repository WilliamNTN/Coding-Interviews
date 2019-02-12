/*
Given an array of size n, find the majority element
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
*/

//Boyer-Moore majority voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(); if(n == 0) return 0;
        
        int element, count = 0;
        
        for(int i = 0; i < n ; i++){
            if(count == 0){
                count++;
                element = nums[i];
            }
            else if(nums[i] == element){
                count++;
            }
            else{
                count--;
            }
        }
        
        return element;
    }
};