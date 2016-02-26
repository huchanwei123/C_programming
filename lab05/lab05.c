/*ee231002 lab05.continued fraction
	102061247,chan-wei hu
	3/24/2014
*/

#include <stdio.h>					//header for I/O library

int main(void){
	int x, n;						//x is the variable to calculate, n is used for switch
	double sqrt1, sqrt2, a;		
									//sqrt1 is the previous number
									//sqrt2 is the number calculated by sqrt1
									//a is used to save sqrt1
	printf("       x    sqrt(x)\n");//first, print out x and sqrt(x)
	for(n=1; n<=8; n++){			//this loop is used to choose case
		switch(n){					//choose case
			case 1:x=2; break;
			case 2:x=11; break;
			case 3:x=121; break;
			case 4:x=1221; break;
			case 5:x=12321; break;
			case 6:x=123321; break;
			case 7:x=1234321; break;
			case 8:x=12344321;
		}

    	for(sqrt1=1+(x-1.0)/2, sqrt2=0; sqrt1-a>=1e-9 || sqrt1-a<=-1e-9; ){
									//loop used to calculate
									//if "sqrt1-a" is larger than 1e-9 or smaller than -1e-9, then continue the loop
        	sqrt2=1+(x-1)/(1+sqrt1);//found the sqrt2 calculated bu sqrt1
        	a=sqrt1;				//save sqrt1 to a
        	sqrt1=sqrt2;			//shift sqrt2 to sqrt1, and find the next sqrt2
    	}
    	printf("%8d %14.9lf\n", x, sqrt2);
									//print out all the value
	}
	return 0;						//the end
}
