#include <iostream>
using namespace std;



// Time: O(n), Space: O(1)
int max1With1Flip(string value){

	int maxWith0 = 0;
	int maxWith1 = 0;
	int maxSofar = 0;
	for(int i = 0; i < value.size();i++){
		if(value[i] == '1'){
			maxWith0++;
			maxWith1++;
		}
		else{
			maxWith1 = maxWith0+1;
			maxWith0 = 0;
		}

		maxSofar = max(maxSofar,maxWith1);
	}

	return maxSofar;
}


int main(){

	string c;
	cin>>c;
	cout<<max1With1Flip(c)<<endl;
}