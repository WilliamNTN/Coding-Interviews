/*
Given a string that consists of brackets, write a function
bracketMatch that takes a bracket string as an input and returns
the minimum number of brackets you’d need to add to the input in
order to make it correctly matched.
*/

#include <iostream>
#include <string>

using namespace std;

//Time: O(n), Space: O(1)

int bracketMatch( const string& text ){
  
  if(text.size() == 0) return 0;
  
  int ans = 0;
  int openBracketCount = 0;
  
  for(int i = 0; i < text.size(); i++){
    if(text[i] == '(')
      openBracketCount++;
    else{
      if(openBracketCount == 0) //error
         ans++;
      else   openBracketCount--;  //stack "pop"
    }
  }
  ans += openBracketCount;
  return ans;
  
}

int main() {
  return 0;
}