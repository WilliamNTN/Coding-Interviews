#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;


int deletionDistance(string str1, string str2, int index1, int index2, vector<vector<int>> memo){

  if(index1 == str1.size()) return str2.size() - index2;
  if(index2 == str2.size()) return str1.size() - index1;
  
  if(memo[index1][index2] != -1)
    return memo[index1][index2];

  int ans = INT_MAX;
  
  ans = min(ans,deletionDistance(str1,str2,index1+1,index2,memo)) + 1;
  ans = min(ans,deletionDistance(str1,str2,index1,index2+1,memo)) + 1;
  
  return memo[index1][index2] = ans;
}
int deletionDistance( const string& str1, const string& str2 ){
  if(str1.size() == 0) return str2.size();
  if(str2.size() == 0) return str1.size();
  vector<vector<int>> memo(str1.size());
  for(int i = 0; i < str1.size(); i++){
    vector<int> aux(str2.size());
    memo[i] = aux;
  }
  
  // there is a function i c++ to fill an arra with a default value, i dont remember its name
  //so i will iterate 
  
  for(int i = 0; i < str1.size(); i++)
    for(int j = 0; j < str2.size(); j++)
      memo[i][j] = -1;
  
  return deletionDistance(str1,str2,0,0,memo);
}

int main() {
  
  string a = "head";
  string b = "hit";
  cout<<"Way"<<endl;
  int ans = deletionDistance(a,b);
  cout<<"Result:" << ans<<endl;
  return 0;
}