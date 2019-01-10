#include <iostream>
#include <string.h>
#include <set>
using namespace std;

string integerToBinaryString(int value){
	string result = "";
	if(value == 0) return "0";
	int mask = 1;
	while(value != 0){

		int aux = value;
		aux = aux & mask;
		if(aux == 1) result = '1' + result;
		else		 result = '0' + result;

		value = value >> 1;
	}
	return result;
}

int binaryStringToInteger(string binary){
	int result = 0;
	for(int i = 0; i < binary.size(); i++){
		if(binary[i] == '1'){
			result += 1;
		}
		if(i != (binary.size()-1))
			result <<= 1;
	}
	return result;
}

string decimalToString(double value){
	string result = "0.";
	set<double> seen;

	while(value != 0){
		if(seen.count(value) > 0) break;
		seen.insert(value);
		double aux = value*2;
		int integer = int(aux);
		result += integer ? '1' : '0';
		value = aux - integer;
	}
	return result;
}

int main(){


	// int v; cin>>v;
	// while(v != -1){
	// 	cout<<integerToBinaryString(v)<<endl;
	// 	cin>>v;
	// }

	// string s;
	// cin>>s;
	// cout<<binaryStringToInteger(s)<<endl;

	double c;
	cin>>c;
	while(c != -1){
		cout<<decimalToString(c)<<endl;
		cin>>c;
	}

	return 0;
}