/*EE231002 Lab07. Matrix Determinant
	102061247, chan-wei hu
	date:4/7
*/

#include <stdio.h>						//header for I/O library
#if !defined(N)
#define N 3								//define N
#endif
double A[N][N];
double det(double A[N][N], int dim);	//function declaration

int main(void){
	int row, col;						//variable declaration
	for(row=0;row<N;row++){				//read in the matrix
		for(col=0;col<N;col++){	
			scanf("%lf", &A[row][col]);
		}
	}		
	printf("Matrix A is\n");			//print
	for(row=0; row<N; row++){			//print out the matrix
		for(col=0; col<N; col++){
			printf(" %2.lf", A[row][col]);
		}
		printf("\n");
	}
	printf("det(A) = %.lf\n", det(A,N));
										//print out the result
	return 0;
}

double det(double A[N][N], int dim){
										//function definition
	int row, col,k=1,i;					//set the variables
	double B[N][N];
	double plus_det=0;
	
	if(dim==2){							//if dim become 2, then do the determinant 
        plus_det=A[0][0]*A[1][1]-A[1][0]*A[0][1];
        return plus_det;				//return the value
    }

	if(dim>2){							//if dim>2, then do the following
		for(i=0; i<dim; i++){			//loop used for positive or negative 
			for(row=0; row<dim-1; row++){//loops used for save the array A into new array B
				for(col=0; col<dim; col++){
					if(col<i){
						B[row][col]=A[row+1][col];
					}
					else if(col>i){
						B[row][col-1]=A[row+1][col];
					}
				}
			}
			plus_det+=k*A[0][i]*det(B,dim-1);
			k *= -1;						//do the recursive
		}	
		return plus_det;			//return the value
	}
}
