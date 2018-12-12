

#include <iostream>
using namespace std;

const int maxN = 101234;



void printMatrix(int** matrix, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
}



//TIME O(n^2), Space O(1)
int** rotateMatrix(int** matrix, int size){

	int startLine = 0;
	int startCol = 0;

	int a,b;
	int l = size;
	while(l > 1){
		a = 0; b = l-1;
		for(int k = 0; k < (l-1); k++){
			int thisLine = startLine;
			int thisCol = startCol;
			int lineFactor[4] = {a,b,-a,-b};
			int colFactor[4] = {b,-a,-b,a};

			int aux1 = matrix[thisLine][thisCol];
			int aux2;
			for(int i = 0; i < 4; i++){
				cout<<"L: "<<thisLine<<" C: "<<thisCol<<endl;
				thisLine += lineFactor[i];
				thisCol += colFactor[i];
				aux2 = matrix[thisLine][thisCol];
				matrix[thisLine][thisCol] = aux1;
				aux1 = aux2;
			}
			cout<<"_----------_"<<endl;
			startCol++;
			a++; b--;
		}
		cout<<"Change Size"<<endl;
		startLine++;
		startCol = startLine;
		l -= 2;
	}

	printMatrix(matrix,size);	
}

int main(){
	int s; cin>>s;
	int**matrix = (int**)malloc(sizeof(int*)*s);
	for(int i =0; i <s; i++) matrix[i] = (int*)malloc(sizeof(int)*s);

	for(int i = 0 ; i < s; i++){
		for(int j = 0; j < s; j++){
			cin>>matrix[i][j];
		}
	}

	matrix = rotateMatrix(matrix,s);

	
}