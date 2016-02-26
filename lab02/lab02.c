/*EE231002 lab02. Pi and sine function
	102061247 chan-wei hu
	Date:3/3/2014
*/

#include <stdio.h>

int main(void){

	float pi ,x ,sinx ;						//declare the variables
	
	pi=(((1.0/24.0)-(1.0/120.0)+(1.0/336.0)-(1.0/720.0)+(1.0/1320.0)-(1.0/2184.0))*4.0)+3.0;
									   		//calculate the value of pi
	x=pi/6.0;						   		//let x=pi/6
	sinx=x-(x*x*x/(3.0*2.0*1.0))+(x*x*x*x*x/(5.0*4.0*3.0*2.0*1.0))-(x*x*x*x*x*x*x/(7.0*6.0*5.0*4.0*3.0*2.0*1.0));			  	  		  
											//calculate sin(pi/6)
	printf("pi = %lg\n",pi);		   		//print out the result
	printf("sin(pi/6) = %lf\n",sinx);  		//print out sin(pi/6)
	return 0;								//the end
}
