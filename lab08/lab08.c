/*EE231002 lab08.BlackJack
	102061247, chan-wei hu
	date:4/21
*/

#include <stdio.h>							//header for I/O library
#include <stdlib.h>
#define n 10000								//define n=10000


int main(void){
	int fir_point, i, k;					//set the variables
	double expected_val, sum, m, a, sum1;

	printf("Points	E(hit) % Busted\n");	//first print out the headline
	for(fir_point=2; fir_point<=20; fir_point++){
											//run the point 2 to 20
		sum=0;								//initialization
		sum1=0;
		m=0;
		for(i=0; i<n; i++){					//run n times to find out expected value
			k=rand()%13+1;					//recieve the random number
			if(k>=11){						//if we get J, Q, K, then they are 10
				k=10;
			}
			if(k==1 && fir_point<11){		//Ace will be 11 when the point<11
				k=11;
			}
			sum+=k;							//sum up all the posibilities
			sum1=fir_point+k;				//sum1 is used to calculate if it will busted
			if(sum1>21){					//if it busted, then count 1
				m++;
			}
		}
		expected_val = sum/n+fir_point;		//calculate expected value
		printf("%4d  %8.2lf%8.2lf\n", fir_point, expected_val, (m/n)*100);
											//print out the answer	
	}
	m=0;
	for(i=0; i<n; i++){						//a loop used to play 10000 times
		sum=0;
		a=0;							
		while(sum<21){						//if sum<21, then continue doing
			k=rand()%13+1;
			if(k==1){						//if k=1, then there are two conditions
				if(sum<=10){				//if sum<=10, then k=11
					sum+=11;
					a=1;					//check that we have use an ACE
				}
				else sum+=1;				//if sum>10,k=1
			}
			else if(k>10){					//if k=J,Q,K, then k=10
				sum+=10;
			}
			else sum+=k;
			if(sum>21 && a==1){				//if it is busted and there are ACE in the sum, change one ACE to 1
				sum=sum-10;
				a=0;
			}
		}
		if(sum==21){						//if black jack, count m for one time
			m++;
		}		
	}
	printf("\n");
	printf("Probability of getting 21 points is %4.2lf%\n", (m/n)*100);
											//print out the answer
	return 0;								//the end
}
