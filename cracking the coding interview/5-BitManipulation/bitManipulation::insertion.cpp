// Youare given a two 32-bit numbers, N and M, and two bit positions, i and j.
// Write a method to insert M into N such that M starts at bit j and ends at i
// You can assueme that the bits j through i have enough space to fit all of M.


#include <iostream>
using namespace std;

int insertion(int n, int m, int i, int j){
	int allones = ~0;
	int left = allones << (j+1);
	int right = ((1<<i)-1);
	int mask = left | right;
	int cleared = n & mask;
	int result = cleared | (m << i);
	return result;
}

int main(){
	int n,m,i,j;
	cin>>n>>m>>i>>j;
	cout<<insertion(n,m,i,j)<<endl;
}