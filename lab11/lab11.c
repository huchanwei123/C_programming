/*ee231002 lab11.Academic Competition
	102061247, chan-wei hu
	date:5/12
*/

#include <stdio.h>
#include "lab11.h"

int main(void){
	int i, j, largest_score;		//variable declaration
	char temp1[5],temp2[5];
	int count=0;						

	for(i=0; i<N; i++){
		scanf("%s%s%d%d%d%s%d%s%d", all[i].fName, all[i].lName
		, &all[i].mathScore, &all[i].physScore, &all[i].chemScore
		, temp1, &all[i].ap1Score,temp2, &all[i].ap2Score);
									//scan in the student
		if(temp1[0]=='m')			//if we scan in the first alphabet is 'm', assign math to ap1
			all[i].ap1 = math;
		else if(temp1[0]=='p')		//if we scan in the first alphabet is 'p', assign math to ap1
			all[i].ap1 = phys;
		else if(temp1[0]=='c')		//if we scan in the first alphabet is 'c', assign math to ap1
			all[i].ap1 = chem;		
		if(temp2[0]=='m')
			all[i].ap2 = math;
		else if(temp2[0]=='p')
			all[i].ap2 = phys;
		else if(temp2[0]=='c')
			all[i].ap2 = chem;
			
		all[i].total=all[i].mathScore + all[i].physScore + all[i].chemScore + all[i].ap1Score + all[i].ap2Score;
									//sum up the score
	}

	printf("Academic Achievement Award Winners:\n");
	for(largest_score=500; largest_score>0; largest_score--){
									//the loop used to find the first to fifth score
		for(j=0; j<N && count<5; j++){
									//check all students
			if(all[j].total==largest_score){
				printf("  %s %s %d\n", all[j].fName, all[j].lName, all[j].total);
				count++;			//count
				all[j].winAAA=1;	//the student who win AAA may not win another
			}
		}
	}
	printf("\n");

	/*
	the following statements are used to check that
	if the student's advanced subject1 or advanced subject2 is math.
	*/

	count=0;
	printf("Mathematics Award Winners:\n");
	for(largest_score=200; largest_score>0; largest_score--){
							//the loop used to find who can win the award
        for(j=0; j<N && count<5; j++){
							//just find the first five students, use "count" to control, if we find all five student, then stop
            if(all[j].ap1==math && all[j].winAAA!=1){
							//check if the student select math for advanced subject and didn't win AAA
                if(all[j].mathScore + all[j].ap1Score==largest_score){
							//print out the first five student
                    printf("  %s %s %d\n", all[j].fName, all[j].lName, largest_score);
                    count++;
                }
            }
            if(all[j].ap2==math && all[j].winAAA!=1){
							//check if the student select math for advanced subject and didn't win AAA
                if(all[j].mathScore + all[j].ap2Score==largest_score){
							//print out the first five student
                    printf("  %s %s %d\n", all[j].fName, all[j].lName, largest_score);
                    count++;
                }
            }
        }
    }
	printf("\n");

	/*
    the following statements are used to check that
    if the student's advanced subject1 or advanced subject2 is physics.
    */

	count=0;
	printf("Physics Award Winners:\n");
    for(largest_score=200; largest_score>0; largest_score--){
							//the loop used to find who can win the award
        for(j=0; j<N && count<5; j++){
							//just find the first five students, use "count" to control, if we find all five student, then stop
            if(all[j].ap1==phys && all[j].winAAA!=1){
							//check if the student select math for advanced subject and didn't win AAA
                if(all[j].physScore + all[j].ap1Score==largest_score){
							//print out the first five student
                    printf("  %s %s %d\n", all[j].fName, all[j].lName, largest_score);
					count++;
                }
            }
            if(all[j].ap2==phys && all[j].winAAA!=1){
							//check if the student select math for advanced subject and didn't win AAA
                if(all[j].physScore + all[j].ap2Score==largest_score){
							//print out the first five student
                    printf("  %s %s %d\n", all[j].fName, all[j].lName, largest_score);
					count++;
                }
            }
        }
    }
	printf("\n");

	/*
    the following statements are used to check that
    if the student's advanced subject1 or advanced subject2 is chemistry.
    */

	count=0;
    printf("Chemistry Award Winners:\n");
    for(largest_score=200; largest_score>0; largest_score--){
							//the loop used to find who can win the award
        for(j=0; j<N && count<5; j++){
							//just find the first five students, use "count" to control, if we find all five student, then stop
            if(all[j].ap1==chem && all[j].winAAA!=1){
							//check if the student select math for advanced subject and didn't win AAA
                if(all[j].chemScore + all[j].ap1Score==largest_score){
							//print out the first five student
                    printf("  %s %s %d\n", all[j].fName, all[j].lName, largest_score);
					count++;
                }
            }
            if(all[j].ap2==chem && all[j].winAAA!=1){
							//check if the student select math for advanced subject and didn't win AAA
                if(all[j].chemScore + all[j].ap2Score==largest_score){
							//print out the first five student
                    printf("  %s %s %d\n", all[j].fName, all[j].lName, largest_score);
					count++;
                }
            }
        }
    }
	return 0;				//the end
}	
