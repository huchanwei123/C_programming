/*ee231002 lb03. Roman Numeral
	102061247 , chan-wei Hu
	2014/3/10
*/
#include <stdio.h>									//header for IO lib

int main(void){
	int num, num1, num2, num3, num4; 				//set the variables
	printf("Input an integer between 1 and 3000: ");//print out the question
	scanf("%d", &num);								//scan the input integer
		num1=num/1000;								//calculate num1
			switch(num1){							//choose the case and print
				case 1: printf("M"); break;
				case 2: printf("MM"); break;
				case 3: printf("MMM"); break;
			}
		num2=(num-(1000*num1))/100;					//calculate num2
			switch(num2){							//choose the case and print
				case 1: printf("C"); break;
				case 2: printf("CC"); break;
				case 3: printf("CCC"); break;
				case 4: printf("CD"); break;
				case 5: printf("D"); break;
				case 6: printf("DC"); break;
				case 7: printf("DCC"); break;
				case 8: printf("DCCC"); break;
				case 9: printf("CM"); break;
			}
		num3=(num-(1000*num1)-(100*num2))/10;		//calculate num3
			switch(num3){							//choose the case and print out
				case 1: printf("X"); break;
				case 2: printf("XX"); break;
				case 3: printf("XXX"); break;
				case 4: printf("XL"); break;
				case 5: printf("L"); break;
				case 6: printf("LX"); break;
				case 7: printf("LXX"); break;
				case 8: printf("LXXX"); break;
				case 9: printf("XC"); break;
			}
		num4=num%1000%100%10;						//calculate num4
			switch(num4){							//choose the case and print out
				case 1: printf("I"); break;
                case 2: printf("II"); break;
                case 3: printf("III"); break;
                case 4: printf("IV"); break;
                case 5: printf("V"); break;
                case 6: printf("VI"); break;
                case 7: printf("VII"); break;
                case 8: printf("VIII"); break;
                case 9: printf("IX"); break;
			} 
		printf("\n");
	return 0;										//the end
}
