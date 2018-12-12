// Write a method to replace all spaces in a string with '%20'.

#include <iostream>
#include <string>

using namespace std;

//Time O(n), Space O(n)
string replaceSub(string s){
	string final;

	for (int i = 0; i < s.size();i++){
		if(s[i] == ' ') final += "%20";
		else final += s[i];
	}
	return final;
}

// Time O(n), Space O(n), O(1) in one point of view
string replaceInPlace(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' '){
			s = s.substr(0,i) + "%20" + s.substr(i+1,s.size()-i);
			i+=2;
		}
	}

	return s;
}
int main(){
	string entry;
	getline(cin,entry);
	cout<<replaceInPlace(entry)<<endl;
}