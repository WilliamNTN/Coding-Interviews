// The problem consist in coding the pancakeSort, which is a sorting algorithm
// that can only use the function flip to modify the array. This function flips the
// first k elemets of an array.

// The approach is to find the maximun value of the array, fliping it to the first
// position, and then flipping it to the last position. From here, repeat the operation
// for the n-1 elements. This way, the algorithm works similiar to selection sort.


#include <iostream>
#include <vector>
using namespace std;

void flip(vector<int> &arr, int k){ // time O(k), space O(1)

	for(int i = 0; i<(k/2);i++){
		int temp = arr[i];
		arr[i] = arr[k-i-1];
		arr[k-i-1] = temp;
	}
}

vector<int> pancakeSort(const vector<int>& arr){// time O(n^2), space O(1)

	vector<int> result(arr.begin(),arr.end());

	for(int i = result.size()-1; i>=0; i--){
		int maxIndex = 0;

		for(int j = 1; j<=i; j++)
			if(result[j] > result[maxIndex]) maxIndex = j;

		flip(result,maxIndex+1);
		flip(result,i+1);
	}

	return result;
}

int main(){

	return 0;
}