
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
        int pointerNext = m+n-1;
        int pointer1 = m-1;
        int pointer2 = n-1;
        
        while(pointer2 >= 0 && pointer1 >= 0){
            if(nums1[pointer1] > nums2[pointer2]){
                nums1[pointerNext--] = nums1[pointer1--];
            }
            else{
                nums1[pointerNext--] = nums2[pointer2--];
            }
        }
        
        while(pointer2 >= 0){
            nums1[pointerNext--] = nums2[pointer2--];
        }
    }
};