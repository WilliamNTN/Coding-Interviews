/*
Given an array arr of distinct integers and a nonnegative integer k, write a function findPairsWithGivenDifference
that returns an array of all pairs [x,y] in arr, such that x - y = k. If no such pairs exist, return an empty array.
Note: the order of the pairs in the output array should maintain the order of the y element in the original array.
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;
// Time: O(n), Space: O(n)
vector<vector<int>> findPairsWithGivenDifference( const vector<int>& arr, int k){
  
  vector<vector<int>> ans;
  set<int> hash;
    
  for(int i = 0; i < arr.size(); i++){ // O(n)
    hash.insert(arr[i]);
  }
  
 for(int i = 0; i < arr.size(); i++){ // O(n)
    int y = arr[i];    
    if(hash.find(k+y) != hash.end()){
      vector<int> thisAns(2);
      thisAns[0] = k+y;
      thisAns[1] = y;
      ans.push_back(thisAns);
    }
  }
  
  return ans;
}

int main() {
  
  return 0;
}