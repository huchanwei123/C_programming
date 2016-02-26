/*ee231002 lab01 unit conversion
	102061247, chan-wei hu
	date:2/24
*/

#include <stdio.h>						//header for IO lib
int main(void)
{
	int kilo,pound,ounce,allounce;		//set the variables
	printf("Input weight in Kg: ");		//print out the question
	scanf("%d", &kilo);					//scan the input value
	allounce=1000*kilo/(453.592/16);	//start calculate
	pound=allounce/16;
	ounce=allounce%16;
	printf("Weight in US customary units: %d pound(s) %d ounce(s)\n",pound,ounce);										
										//print out the result	
	return 0;							//the end
}

