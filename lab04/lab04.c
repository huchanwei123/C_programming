/*ee231002 lab04 balanced prime number
	102061247,chan-wei hu
	date:3/17
*/

#include <stdio.h>										//header for I/O library

int main(void){

	int prime_a=3, d, prime_b=5, num;					//set the variable and initialize
	int prime_c;										//prime_c is the number we want to find
		for(prime_c=7,num=1; prime_c<=300000,num<=1000; prime_c+=2){
														//this loop is used to find prime_c
			for(d=2; d*d < prime_c; d++){				//start calculate
				if(prime_c%d==0)						//if prime_c%d==0, then it is not a prime num
					break;
			}
			if(prime_c%d != 0){							//the statement to choose prime num and continue
				if((prime_a+prime_c)/2==prime_b){		
					if(num<=10 || num>=991)				//the number we want to print
						printf("Balanced Prime Number #%d: %d\n", num, prime_b);
														//print out the result
						num++;
				}
				
			prime_a=prime_b;							//move prime_b to prime_a
			prime_b=prime_c;							//move prime_c to prime_b
			}				
		}
		
	return 0;											//the end
}
