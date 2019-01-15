/*
Given an array arr of unique nonnegative integers
implement a function getDifferentNumber that finds the
smallest nonnegative integer that is NOT in the array.
*/

#include <iostream>
#include <vector>
using namespace std;

//Time: O(n)
// Space: O(1) ignore ans vector because parameter is const

int getDifferentNumber( const vector<int>& arr ){
  if(arr.size() == 0) return 0;
  vector<int> ans(arr.begin(),arr.end());
  
  for(int i = 0; i < ans.size(); i++){
    int value = ans[i];
    
    while(value < ans.size() && ans[value] != value){
      int temp = ans[value];
      ans[value] = value;
      value = temp;
    }
  }
  
  for(int i = 0; i < arr.size(); i++)
    if(ans[i] != i) return i;
  
  return ans.size();
}

int main() {
  return 0;
}