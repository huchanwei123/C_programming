/*EE231002 Lab06. Magic squares
	102061247, chan-wei hu
	date:4/4
*/

#include<stdio.h>					//header for I/O library
#define N 2							//define the value of N
int main(void)
{
    int x, y, i, t=0, count, sum=0, check;
									//set the vaiables
    int A[N*N], Q[N*N], magic[N][N];//set the arrays
    for(i=1;i<=N*N;i++)				//initialize the array A[i]
        A[i-1]=i;

    for(x=0; x<N; x++){				//reset the multidimensional array
        for(y=0; y<N; y++){
            magic[x][y]=0;
        }
    }

    for(count=1; ;count++){			//start to count and check
        for(i=0,x=-1;i<=N*N-2;i++){	//find A[i]<A[i+1], if we find it, then x=i
            if(A[i]<A[i+1])
                x=i;
        }
        if(x==-1) break;			//others if no match, then stop the loop
        for(i=0;i<=N*N-1;i++){		//find A[i]>A[x]
            if(A[i]>A[x])
                y=i;
        }
        i=A[x];						//swap A[x] and A[y]
        A[x]=A[y];
        A[y]=i;
        for(i=0;i<=x;i++){			//the value don't change at A[0] to A[x]
            A[i]=A[i];
        }
        for(i=x+1;i<=N*N-1;i++){	//save A[x+1] to A[N*N-1] into array Q
            Q[i]=A[i];
        }
        for(i=x+1;i<=N*N-1;i++){	//reverse the array
            A[N*N+x-i]=Q[i];
        }
        for(i=0;i<=N*N-1;i++){		//we find the other arrangement for A[i] and change it to magic[x][y]
            x=i/N;
            y=i%N;
            magic[x][y]=A[i];
        }
    
		check=1;	   				//set check=1 to start to check
		if(check==1){				
			sum=0;
			for(i=0; i<N; i++){		//calculate the sum of diagonal
				sum+=magic[i][i];
			}
			if (sum!=N*(N*N+1)/2){	//if sum is not equal to N*(N*N+1)/2, then check=0	   
				check=0;
			}
		}

		if (check==1){				//if the above check==1, then start to check anti-diagonal
			sum=0;
			for(i=0; i<N; i++){		//calculate the sum of anti-diagonal
				sum+=magic[i][N-i-1];
			}
			if (sum!=N*(N*N+1)/2){ 	//if sum is not equal to N*(N*N+1)/2, then check=0
				check=0;
			}
		}
		
		if (check==1){				//if the above check=1, then start to check column
			for(x=0; x<N; x++){		//start to calculate the sum of column
				sum =0;
				for(y=0; y<N; y++) {
					sum+=magic[x][y];
				}
				if (sum!=N*(N*N+1)/2){//if the sum is not equal to N*(N*N+1)/2, then check=0
					check=0; break;
				}
			}
		}
		if (check==1){				//if the above check==1, then start to check row
			for(y=0; y<N; y++){		//start to calculate the sum of row
				sum =0;
				for(x=0; x<N; x++) {
					sum+=magic[x][y];
				}
				if (sum!=N*(N*N+1)/2){//if the sum of row is not equal to N*(N*N+1)/2, then check=0
					check= 0; break;
				}
			}
		}
        if(check==1){				//if all of conditions are right, then print out the square
        	t++;
        	printf("Magic Square #%d:\n", t);
            for(x=0; x<N; x++){
                for(y=0; y<N; y++){
                    printf(" %2d", magic[x][y]);
                }
                printf("\n");
            }
    	}
	}printf("Total number of magic squares found = %d\n", t);
									//print out the total number of squares
    return 0;						//the end
}
