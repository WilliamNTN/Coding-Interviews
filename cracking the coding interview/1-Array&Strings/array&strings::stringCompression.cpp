#include <iostream>
using namespace std;


string compress(string s){
	string ret = "";
	int i = 0;
	while(i < s.size()){
		char at = s[i];
		int count = 0;
		while(s[i] == at){
			i++; count++;
		}
		ret += at;
		ret += count + '0';
	}
	
	if(ret.size() < s.size()) return ret;
	return s;

}

int main(){

	string s;
	cin>>s;

	cout<<compress(s)<<endl;
}