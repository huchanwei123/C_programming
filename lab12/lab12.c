/*ee231002 lab12.Polynomials
	102061247, chan-wei hu
	date:5/19
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPoly{		//define the type
	int degree;
	double coef;
	struct sPoly *next;
}POLY;

POLY *oneTerm(int degree, double coef);
							//function declaration
POLY *add(POLY *p1, POLY *p2);
POLY *sub(POLY *p1, POLY *p2);
POLY *mply(POLY *p1, POLY *p2);
void print(POLY *p1);
void release(POLY *p1);

int main(void){

	POLY *X=oneTerm(1, 1.0);//get x
	POLY *One=oneTerm(0, 1.0);
							//get 1
	POLY *A=add(X, One);	//get x+1
	POLY *A2=mply(A, A);	//multiple (x+1) and (x+1)
	POLY *A3=mply(A2, A);
	POLY *A4=mply(A3, A);
	POLY *A5=mply(A4, A);

	printf("A = ");
	print(A);				//print out the result
	printf("A2 = ");
	print(A2);
	
	POLY *B=sub(X, One);	//get x-1
	POLY *B2=mply(B, B);	//multiple (x-1) and (x-1)
	POLY *B3=mply(B2, B);
	POLY *B4=mply(B3, B);
	POLY *B5=mply(B4, B);
	
	POLY *C=add(A, B);		//add A and B
	POLY *C2=mply(A2, B2);
	POLY *C3=mply(A3, B3);
	POLY *C4=mply(A4, B4);
	POLY *C5=mply(A5, B5);
	
	printf("C = ");
	print(C);				//print out the result
	printf("C2 = ");
	print(C2);

	printf("C3 = ");
	print(C3);
	printf("C4 = ");
	print(C4);
	printf("C5 = ");
	print(C5);
	
	release(X);
	release(One);
	release(A);
	release(A2);
	release(A3);
	release(A4);
	release(A5);	
	release(B);
	release(B2);
	release(B3);
	release(B4);
	release(B5);
	release(C);
	release(C2);
	release(C3);
	release(C4);
	release(C5);

	return 0;		
}

POLY *oneTerm(int degree, double coef){

	POLY *new_term=malloc(sizeof(POLY));
							//get a new space from the computer
	new_term->degree=degree;
							//new_term's degree points to degree
	new_term->coef=coef;	//new_term's coef points to coef
	new_term->next=NULL;

	return new_term;
}

POLY *add(POLY *p1, POLY *p2){
							//function used to add p1 and p2

	POLY *new_poly=NULL;
	POLY *current_term=NULL;
	POLY *previous_term=NULL;
	
	while(p1!=NULL){		//when p1 is not a NULL
		if(new_poly==NULL){	
			new_poly=oneTerm(p1->degree, p1->coef);
			current_term=new_poly;
							//save new_poly to current_poly
		} 
		else{
			current_term->next=oneTerm(p1->degree, p1->coef);
			current_term=current_term->next;
		}
		p1=p1->next;		//the assignment advances p1 pointer from one node to the next 
	}

	while(p2!=NULL){		//when p2 is not a NULL
		previous_term=NULL;
		for(current_term=new_poly; current_term!=NULL; previous_term=current_term, current_term=current_term->next){
			if(p2->degree==current_term->degree){
				current_term->coef += p2->coef;
							//if the degree are the same, then add the coef
				if (current_term->coef==0.0){
							//if the coef is 0, check if previous_term is a NULL, if not, then the pointer in the pervious node point to the node after the current node
				  	if(previous_term==NULL){
						new_poly=new_poly->next;
						free(current_term);
				  	} 
					else{
						previous_term->next=current_term->next;
						free(current_term);
				  	}
				}
				break;
			}
		}
		previous_term=NULL;
		if(current_term==NULL){
							//if current_term is a NULL
			for(current_term=new_poly; current_term!=NULL; previous_term=current_term, current_term=current_term->next){
				if(p2->degree > current_term->degree){
							//if p2's degree is larger than p1's degree, check if previous_term is a NULL. 
					if(previous_term==NULL){
						new_poly=oneTerm(p2->degree, p2->coef);
						new_poly->next=current_term;
					} 
					else{
						previous_term->next=oneTerm(p2->degree, p2->coef);
						previous_term->next->next=current_term;
					}
					break;
				}
			}
			if(current_term==NULL){
				previous_term->next=oneTerm(p2->degree, p2->coef);
			}
		}
		p2=p2->next;		//the assignment advances p2 pointer from one node to the next
	}	
	return new_poly;			
}


POLY *sub(POLY *p1, POLY *p2){
							//function used to subscribe p1 and p2
	POLY *current_term_p2=NULL;	
	POLY *new_poly=NULL;

	current_term_p2=p2;
	while(current_term_p2!=NULL){
							//when current_term_p2 is not a NULL
		current_term_p2->coef= (-1)*(current_term_p2->coef);
							//change p2's coef to a negative number
		current_term_p2=current_term_p2->next;
	}
	new_poly=add(p1, p2);	//add p1 and p2

	return new_poly;
}


POLY *mply(POLY *p1, POLY *p2){

	POLY *current_term=NULL;
	POLY *previous_term=NULL;
	POLY *current_term_p2=NULL;	
	POLY *new_poly=NULL;

	while(p1!=NULL){		//when p1 is not a NULL
		current_term_p2=p2;	
		while(current_term_p2!=NULL){
			if(new_poly==NULL){
				new_poly=oneTerm(p1->degree + current_term_p2->degree, p1->coef * current_term_p2->coef);
							//plus the degree and multiple the coef
			} 
			else{
				for(current_term=new_poly; current_term!=NULL; previous_term=current_term, current_term=current_term->next){
					if((p1->degree + current_term_p2->degree) == current_term->degree){
							//if p1's degree plus current_term_p2's degree equal to current_term's degree, plus the coef of p1's coef multiple current_term_p2's coef to current_term
						current_term->coef += p1->coef * current_term_p2->coef;
						if(current_term->coef==0.0){
							//if current_term's coef is 0, check if the previous_term is a NULL
							if (previous_term==NULL){
								new_poly=new_poly->next;
								free(current_term);
							} 
							else{
								previous_term->next=current_term->next;
								free(current_term);
							}
						}
						break;
					}
				}
				if(current_term==NULL){
					previous_term->next=oneTerm(p1->degree + current_term_p2->degree, p1->coef * current_term_p2->coef);
				}								
			}
			current_term_p2=current_term_p2->next;
							//the assignment advances current_term_p2 pointer from one node to the next
		}
		p1=p1->next;		//the assignment advances p2 pointer from one node to the next
	}

	return new_poly;
}

void release(POLY *p1){
						//the function to release all nodes of p1
	if(p1->next==NULL){
		free(p1);
	} 
	else{
		release(p1->next);
		free(p1);
	}
	return;
}


void print(POLY *p1){
						//function to print out the answer
	if (p1->degree==0){	//if the degree is 0, then only print the coef
		printf("%g", p1->coef);
	} 
	else if(p1->degree==1){
						//if the degree is 1, then check the value of coef and print
		if(p1->coef==1.0){ 
			printf("x");
		} 
		else if(p1->coef== -1.0){
			printf("-x");
		} 
		else{
			printf("%g x", p1->coef);
		}
	} 
	else{
		if(p1->coef==1.0){
						//if the coef is 1 or -1, just print x^degree or -x^degree
			printf("x^%d", p1->degree);
		} 
		else if(p1->coef== -1.0){
			printf("-x^%d", p1->degree);
		}
		else{
			printf("%g x^%d", p1->coef, p1->degree);
		}
	}
	p1=p1->next;		//the assignment advances p1 pointer from one node to the next

	while(p1!=NULL){	//when p1 is not a NULL
		if(p1->degree==0){
						//if the degree is 0, then only print the coef
			printf(" %+g", p1->coef);
		} 
		else if(p1->degree==1){
						//if the degree is 1, then check the value of coef and print
			if(p1->coef==1.0){ 
				printf(" +x");
			} 
			else if(p1->coef== -1.0){
				printf(" -x");
			} 
			else{
				printf(" %+g x", p1->coef);
			}
		} 
		else{
			if(p1->coef==1.0){
						//if the coef is 1 or -1, just print x^degree or -x^degree 
				printf(" +x^%d", p1->degree);
			} 
			else if(p1->coef== -1.0){
				printf(" -x^%d", p1->degree);
			} 
			else{
				printf(" %+g x^%d", p1->coef, p1->degree);
			}
		}
	p1=p1->next;
	}
	printf("\n");

	return;				//the end
}
