// Given two strings, write a method to decide if one is a permutation 
// of the other

#include <iostream>	// IO
#include <string>
#include <algorithm>	// Sort
#include <map>

using namespace std;



// Time: O(nlog(n)), 
// Space: O(1), but the string. True if in-place sorting
bool checkPermutationSorting(string a, string b){
	if(a.size() != b.size())
		return false;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for(int i=0;i<a.size(); i++)
		if(a[i] != b[i])
			return false;

	return true;
}
// Time: O(n). Loop in strings. Real: 2N
// Space: O(2n). Uses map for each char, in the worst case.
bool checkPermutationHash(string a, string b){
	if(a.size() != b.size())
		return false;


	map<char,int> hashA;
	map<char,int> hashB;

	for(int i=0;i<a.size();i++){
		hashA[a[i]]++;
		hashB[b[i]]++;
	}

	if(hashA.size() != hashB.size()) return false;

	map<char,int>::iterator it;

	for(it = hashA.begin(); it != hashA.end(); it++){
		if(hashA[it->first] != hashB[it->first])
			return false;
	}

	return true;
}


int main(){

	string a,b;
	cin>>a>>b;


	cout<<checkPermutationHash(a,b)<<endl;
}