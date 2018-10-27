// Given an image represented by an NxN matrix, where each pixel in the image is
// 4bytes, write a mothod to rotate the image by 90 degrees.
//Can you do this in place?

#include <iostream>
#include <cstdlib>
using namespace std;

//Time: O(n*n)
//Space: O(n*n)
int **rotateMatrix(int **mat, int n){
	int** ret = (int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++) ret[i] = (int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ret[i][j] = mat[(n-1)-j][i];
		}
	}
	return ret;
}


int **rotateMatrixInPlace(int **mat, int n){

}
void printMatrix(int **mat, int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}


}
int main(){
	int n;
	cin>>n;

	int** mat = (int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++) mat[i] = (int*)malloc(sizeof(int)*n);


	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>mat[i][j];


	mat = rotateMatrix(mat,n);
	cout<<endl;
	printMatrix(mat,n);
}