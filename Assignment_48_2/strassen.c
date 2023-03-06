#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ** createZeroMatrix(int n){
	int ** array = (int**)malloc(n*sizeof(int *));	
	int i,j;
	for(i = 0;i < n; i++) {
	    	array[i] = (int*)malloc(n*sizeof(int));
   	 	for(j = 0; j < n; j++) {
	        	array[i][j] = 0;
	    	}
	}
	return array;
} 

int ** create(int n,int pow){
	int ** array = createZeroMatrix(pow);	
	int i,j,no;
	for(i = 0;i < n; i++) {
   	 	for(j = 0; j < n; j++) {
			printf("Enter an element at (%d, %d) position:",i+1,j+1);
			scanf("%d", &no);
	    		array[i][j] = no;
			}
	}
	return array;
} 

void printMatrix(int ** matrix,int n) {
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t\t",matrix[i][j]);
		}
		printf("\n");
	}
}


void compose(int** matrix,int** result,int row,int col,int n){
	int i,j,r=row,c=col;
	for(i=0;i<n;i++){
		c=col;
		for(j=0;j<n;j++){
			result[r][c]=matrix[i][j];	
			c++;	
		}
		r++;
	}
}


int** divide(int ** matrix,int n, int row,int col) {
	int n_new=n/2;	
	
	int ** array = createZeroMatrix(n_new);	
	int i,j,r=row,c=col;
	for(i = 0;i < n_new; i++) {
		c=col;
   	 	for(j = 0; j < n_new; j++) {
        		array[i][j] = matrix[r][c];
			c++;
    		}
		r++;
	}
	return array;
}


int** addMatrix(int** matrixA,int** matrixB,int n){
	int ** res = createZeroMatrix(n);
	int i,j;	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			res[i][j]=matrixA[i][j]+matrixB[i][j];
	
	return res;
}

int** subMatrix(int** matrixA,int** matrixB,int n){
	int ** res = createZeroMatrix(n);
	int i,j;	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			res[i][j]=matrixA[i][j]-matrixB[i][j];
	
	return res;
}


int** strassensMultRec(int ** matrixA, int** matrixB,int n){
	int ** result = createZeroMatrix(n);
	if(n>1) {
		//Divide the matrix
		int ** a11 = divide(matrixA, n, 0, 0);
		int ** a12 = divide(matrixA, n, 0, (n/2));
		int ** a21 = divide(matrixA, n, (n/2), 0);
		int ** a22 = divide(matrixA, n, (n/2), (n/2));	
		int ** b11 = divide(matrixB, n, 0, 0);
		int ** b12 = divide(matrixB, n, 0, n/2);
		int ** b21 = divide(matrixB, n, n/2, 0);
		int ** b22 = divide(matrixB, n, n/2, n/2);
		
		//Recursive call for Divide and Conquer
		int** m1= strassensMultRec(addMatrix(a11,a22,n/2),addMatrix(b11,b22,n/2),n/2);
		int** m2= strassensMultRec(addMatrix(a21,a22,n/2),b11,n/2);
		int** m3= strassensMultRec(a11,subMatrix(b12,b22,n/2),n/2);
		int** m4= strassensMultRec(a22,subMatrix(b21,b11,n/2),n/2);
		int** m5= strassensMultRec(addMatrix(a11,a12,n/2),b22,n/2);
		int** m6= strassensMultRec(subMatrix(a21,a11,n/2),addMatrix(b11,b12,n/2),n/2);
		int** m7= strassensMultRec(subMatrix(a12,a22,n/2),addMatrix(b21,b22,n/2),n/2);

		int** c11 = addMatrix(subMatrix(addMatrix(m1,m4,n/2),m5,n/2),m7,n/2);
		int** c12 = addMatrix(m3,m5,n/2);
		int** c21 = addMatrix(m2,m4,n/2);
		int** c22 = addMatrix(subMatrix(addMatrix(m1,m3,n/2),m2,n/2),m6,n/2);
		//Compose the matrix
		compose(c11,result,0,0,n/2);
		compose(c12,result,0,n/2,n/2);
		compose(c21,result,n/2,0,n/2);
		compose(c22,result,n/2,n/2,n/2);
	} 
	else {
		//This is the terminating condition for recurssion.
		result[0][0]=matrixA[0][0]*matrixB[0][0];
	}
	return result;
}



int ** strassensMultiplication(int ** matrixA, int** matrixB,int n){
	int ** result = strassensMultRec(matrixA,matrixB,n);
	return result;
}

int ** standardMultiplication(int ** matrixA,int ** matrixB,int n) {
	int ** result;
	int i,j,k;

	result = (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		result[i]=(int*)malloc(n*sizeof(int));
		for(j=0;j<n;j++){
			result[i][j]=0;
			for(k=0;k<n;k++) {
				result[i][j]=result[i][j]+(matrixA[i][k]*matrixB[k][j]);
			}		
		}
	}
	return result;
}

int main() {
	int i = 0, j = 0,n = 0;
	printf("Enter order of matrix:");
	scanf("%d",&n);
	//To handle when n is not power of k we do the padding with zero
	int pow = 1;
	while(pow<n){
		pow=pow*2;
	}
	clock_t start, end;
	start = clock();
	printf("\nEnter values for Matrix A\n");
	int ** matrixA = create(n,pow);
	printf("\nEnter values for Matrix A\n");
	int  ** matrixB = create(n,pow);
	n = pow;
	int ** standardRes,**strassenRes;
	
	printf("\nMatrix A\n");
	printMatrix(matrixA,n);
	
	printf("\nMatrix B\n");
	printMatrix(matrixB,n);
	
	
	/*printf("\nStrassen's Multiplication Output:\n");
	int ** strassensRes = strassensMultiplication(matrixA,matrixB,n);
	printMatrix(strassensRes,n);*/
	printf("\nStandard Multiplication Output:\n");
	int ** stdRes = standardMultiplication(matrixA,matrixB,n);
	printMatrix(stdRes,n);
	end = clock();
	printf("Time taken by Standard Multiplication is %.2f", ((double)(end - start)/CLOCKS_PER_SEC));

	return 0;
}



