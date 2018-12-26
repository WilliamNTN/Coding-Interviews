// Given a sorted increasubg array wuth unique elements, write an algorithm 
// to create a binary search tree with minimal heigh


#include <iostream>
using namespace std;


void addToTree(int value){ // Should add in a binary tree
	cout<<"add "<<value<<endl;
}


void buildMinimalTree(int *array, int start, int end){
	if(array == NULL) return;
	if(start > end) return;

	int middle = start + ((end-start)/2);

	addToTree(array[middle]);
	buildMinimalTree(array,start,middle-1);
	buildMinimalTree(array,middle+1,end);
}


int main(){

	int n;
	cin>>n;
	int *arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		cin>>arr[i];

	buildMinimalTree(arr,0,n-1);
}