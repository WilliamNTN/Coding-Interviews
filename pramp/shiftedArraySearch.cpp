
// Given an array shiftedArray, that initially was a sorted unique array
// that gas been left shifted by a number you do not know, and a given
// integer n, search N in shiftedArray and return its index, or -1 if there
// is no solution.

// The approach uses modified binary search to find what a called a pivot,
// which is the position where the array divides in two parts, and applied
// a binary search to the half where the integer N could be.
// Its important to note that de first element of the array will always be
// smallest than any number from the first part, and greater than any element
// from the second part. It can be used to determine where the number N
// is, if it exists.


#include <iostream>
#include <vector>
using namespace std;



int MBS(const vector<int> &arr){ //time O(log n), space O(1)

  int left = 0, right = arr.size()-2;
  int ans = -1;
  
  while(left <= right){
    int middle = (left + (right - left)/2);
    
    if(arr[middle] > arr[middle+1]){
      ans = middle; break;
    }
    if(arr[middle] > arr[0])
      left = middle+1;
    else
      right = middle-1;
  }
  
  return ans;
}

//time O(log n), space O(1)
int BS(const vector<int> &arr, int left, int right, int num){

  while(left < right){
    int middle = (left + (right-left)/2);
    
    if(arr[middle] >= num)
      right = middle;
    else
      left = middle+1;
  }
  
  if(arr[left] == num) return left;
                       return 0;
  
}

//time O(log n), space O(1)
int shiftedArrSearch( const vector<int>& shiftArr, int num ){
    
  int pivot = MBS(shiftArr);
  int ans = -1;
  if(pivot == -1){
    ans = BS(shiftArr,0,shiftArr.size()-1,num);
  }
  else{
    if(num > shiftArr[0])
      ans = BS(shiftArr,0,pivot,num);
    else
      ans = BS(shiftArr,pivot+1,shiftArr.size()-1,num);
  }
  
  return ans;
    
}

int main() {
 
  return 0;
}