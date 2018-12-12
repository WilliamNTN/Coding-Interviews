// Write an algorithm such that if an element in an MXN matrix is 0, its entire row and column are set to zero.



#include<iostream>
using namespace std;

void printMatrix(int **matrix, int n, int m){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
int** zeroMatrix(int** matrix, int n, int m){

	int rowArray[n] = {0};
	int colArray[m] = {0};

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0){
				rowArray[i] = 1;
				colArray[j] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(colArray[j] ==1 || rowArray[i] == 1)
				matrix[i][j] = 0;
		}
	}

	printMatrix(matrix,n,m);
	return matrix;
}


int main(){
	int n,m;
	cin>>n>>m;
	int** matrix = (int**)malloc(sizeof(int*)*n);
	for(int i = 0; i < n; i++) matrix[i] = (int*)malloc(sizeof(int)*m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>matrix[i][j];
		}
	}

	zeroMatrix(matrix,n,m);
}