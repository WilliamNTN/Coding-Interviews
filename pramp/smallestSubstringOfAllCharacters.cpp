// The problem consists in, given and arr of unique chars, and a string,
// find the smallest substring that has all the chars of ARR.

// The approach is to keep two pointers, i and j, and advance j, keeping track
// of how many unique characters there are between the positions i and j.
// When all the chars has been found, keep track of this possible answer
// and start moving pointer i, until all the characters are still present between
// i and j. Doing this while j < string.size() will give the right answer.


#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


string getShortestUniqueSubstring(const vector<char>& arr, const string &str ){// time O(n), space O(n)
 
  
  int pt1 = 0,pt2 = 0;
  string ans = "";
  int count = 0;
  map<char,int> inArr, mp;
  
  for(int i = 0; i<arr.size(); i++){
    inArr[arr[i]] = 1;
    mp[arr[i]] = 0;
  }
  while(pt2 < str.size()){
    
    if(inArr[str[pt2]] == 0){
      pt2++;
      continue;
    }
    
    mp[str[pt2]]++;
    if(mp[str[pt2]] == 1) count++;
    
    while(count >= arr.size()){
      if(inArr[str[pt1]] == 0){
        pt1++; continue;
      }
      string thisAns = str.substr(pt1,pt2-pt1+1);
      if(ans == "" || thisAns.size() < ans.size())
        ans = thisAns;
      
      mp[str[pt1]]--;
      if(mp[str[pt1]] == 0) count--;
      
      pt1++;
    }    
    
    pt2++;
  }
  
  return ans;
     
}

int main() {
  
 return 0;
}