/*ee231002 lab09.GCD and LCM
	chan-wei hu,102061247
	date:4/28
*/

#include <stdio.h>
#define S 20

void factorize(int N, int factor[S], int power[S]);		//function declaration
void GCD(int Afactors[S], int Apower[S], int Bfactors[S],
         int Bpower[S], int Cfactors[S], int Cpower[S]);
void LCM(int Afactors[S], int Apower[S], int Bfactors[S],
         int Bpower[S], int Cfactors[S], int Cpower[S]);
void write(int factor[S], int power[S]);

int main(void){
	int a, b;											//declare a, b as the input variable		
	int Afactors[S]={}, Apower[S]={}, Bfactors[S]={}, Bpower[S]={};
														//array declaration
	int Cfactors[S]={}, Cpower[S]={};					//array declaration
	printf("input A: ");								//print input
	scanf("%d", &a);									//scan input a
	printf("input B: ");								//print input
	scanf("%d", &b);									//scan input b
	factorize(a, Afactors, Apower);						//put in the function to calculate factors
	factorize(b, Bfactors, Bpower);							
	printf("  A = ");
	write(Afactors, Apower);							//calculate the sum of A
	printf("  B = ");
	write(Bfactors, Bpower);							//calculate the sum of B
	printf("  GCD(A,B) = ");
	GCD(Afactors, Apower, Bfactors,Bpower, Cfactors, Cpower);
														//find the GCD of A and B
	write(Cfactors, Cpower);							//calculate the GCD
	printf("  LCM(A,B) = ");
    LCM(Afactors, Apower, Bfactors,Bpower, Cfactors, Cpower);
														//find the LCM of A and B
    write(Cfactors, Cpower);							//calculate the LCM
	return 0;
}

void factorize(int N, int factors[S], int power[S]){
	int fact, i=0, fac_power=0;							//fact means factor
	for(fact=2; fact<=N; fact++){						//find the factor started from 2
		if(N%fact==0){									//if N%fact==0, then start the while loop
			fac_power=0;
			while(N%fact==0){							//if N can be divided by fact, count its power, save it into the array
				N=N/fact;
				factors[i]=fact;
				fac_power++;
				power[i]=fac_power;
			}
			i++;										//i++
		}
	}
	factors[i]=1;
	power[i]=1;	
}

void GCD(int Afactors[S], int Apower[S], int Bfactors[S],
		 int Bpower[S], int Cfactors[S], int Cpower[S])
{
	int x=0, i, j;
	for(i=0; i<S; i++){
		for(j=0; j<S; j++){
			if(Afactors[i]==Bfactors[j] && Afactors[i]!=0){
														//if we find the same factor in A and B, and Afactor[i]!=0
				 Cfactors[x]=Afactors[i];				//save the number into Cfactors[x]
				if(Apower[i]>=Bpower[j]){				//recieve the smaller power
					Cpower[x]=Bpower[j];
				}
				else Cpower[x]=Apower[i];
				x++;									//x++
			}
		}
	}
}
	
void LCM(int Afactors[S], int Apower[S], int Bfactors[S],
		 int Bpower[S], int Cfactors[S], int Cpower[S])
{
	int x=0, i=0, j=0;
	
	while(Afactors[i]!=1 && Bfactors[j]!=1){
														//when Afactors[i] and Bfactors[j] are not 1
		if(Afactors[i]<Bfactors[j]){					//if Afactors[i]<Bfactors[j], save Afactor[i] in Cfactors[x]
			Cfactors[x]=Afactors[i];				
			Cpower[x]=Apower[i];						//save Apower[i] in Cpower[x]
			x++;										//next Cpower[x]
			i++;										//next Afactors[i] and Apower[i]	
		}
		if(Afactors[i]>Bfactors[j]){					//if Afactors[i]>Bfactors[j], save Bfactors[j] in Cfactors[x]
			Cfactors[x]=Bfactors[j];					
        	Cpower[x]=Bpower[j];						//save Bpower[j] in Cpower[x]	
        	x++;										//next Cpower[x]	
        	j++;										//next Bfactors[j] and Bpower[j]
		}
		if(Afactors[i]==Bfactors[j]){					//if Afactors[i]=Bfactors[j], save Afactor[i] in Cfactors[x]
			Cfactors[x]=Afactors[i];						
			if(Apower[i]>=Bpower[j]){					//check whose power is larger	
				Cpower[x]=Apower[i];
			}
			if(Apower[i]<Bpower[j]){
				Cpower[x]=Bpower[j];
			}
			x++;										//next Cpower[x]	
			i++;										//next Afactors[i] and Apower[i]	
			j++;										//next Bfactors[j] and Bpower[j]	
		}
	}
	if(Afactors[i]==1){									//if Afactors[i]=1, save all the lefted Bfactors[j] in Cfactors[x]
		while(Bfactors[j]!=1){
			Cfactors[x]=Bfactors[j];
			Cpower[x]=Bpower[j];						//save the lefted Bpower[j] in Cpower[x]
			x++;
			j++;
		}
	}
	else{												//if Bfactors[j]=1, save all the lefted Afactors[i] in Cfactors[x]
		while(Afactors[i]!=1){
            Cfactors[x]=Afactors[i];
            Cpower[x]=Apower[i];						//save the lefted Apower[i] in Cpower[x]
            x++;
            i++;
        }
	}
	Cfactors[x]=1;		
}

void write(int factors[S], int power[S])
{
	int i, sum=1, times;								//variable declaration
	if(factors[0]==1){									//if the first factor is 1, print out 1
		printf("1");
	}
	for(i=0; i<S-1; i++){								
		if(factors[i]!=1){								//if the factor!=1, calculate the sum
			for(times=0; times<power[i]; times++){		//times is used to calclate how many times factor have to multiple
				sum*=factors[i];
			}
			if(power[i]==1){							//if power==1, only print factor
				printf("%d", factors[i]);
			}
			if(power[i]!=1 && factors[i]!=0){			//if power!=1 and factor!=0, then print factor^power
				printf("%d^%d", factors[i], power[i]);
			}
		}
		if(factors[i+1]!=1 && power[i+1]!=0){			//if the next factor!=1, print "*"
			printf(" * ");
		}
	}
	printf(" = %d\n", sum);								//print out the result of sum
}
