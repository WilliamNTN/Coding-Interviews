// There are three types of edits that can be performed on strings: insert a character, remove a character or replace a character;
// Given two strings, write a function to check if they are one edit( or zero edit) away.

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


// Time: O(n), Space: O(1)
bool checkOneOrLessEdit(string a, string b){

	if(abs((int)(a.size() - b.size())) > 1) return false;

	int diff = 0;

	int ia = 0, ib = 0;

	while(ia < a.size() && ib < b.size()){
		if(a[ia] == b[ib]){
			ia++; ib++;
		}
		else{
			if(diff) return false;
			diff = 1;
			if(a.size() > b.size()) ia++;
			if(b.size() > a.size()) ib++;
			else{
				ia++; ib++;
			}
		}
	}

	diff += (a.size() - ia) + (b.size() - ib);
	if(diff > 1) return false;

	return true;
}


bool checkReplace(string a, string b){
	int diff = 0;

	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i]){
			if(diff) return false;
			diff = 1;
		}
	}

	return true;
}


bool checkInsert(string a, string b){ // check by inserting in A

	int indexa = 0, indexb = 0;

	while(indexa < a.size() && indexb < b.size()){
		if(a[indexa] != b[indexb]){
			if(indexa != indexb) return false;
			indexb++;
		}
		else{
			indexa++; indexb++;
		}
	}
}
bool checkOneEdit(string a, string b){
	if(a.size() == b.size())
		return checkReplace(a,b);
	if(a.size()+1 == b.size())
		return checkInsert(b,a);
	if(a.size()-1 == b.size())
		return checkInsert(a,b);

	return false;
}

int main(){

	string a,b;
	cin>>a>>b;
	cout<<checkOneOrLessEdit(a,b)<<endl;
}