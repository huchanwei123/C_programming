D, Name
   Date:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPoly {
	int degree; 		// the degree of the node
	double coef; 		// the coefficient of the node
	struct sPoly *next; // pointer to the next node
} POLY;

POLY *oneTerm(int degree, double coef);
POLY *add(POLY *p1, POLY *p2);
POLY *sub(POLY *p1, POLY *p2);
POLY *mply(POLY *p1, POLY *p2);
void print(POLY *p1);
void release(POLY *p1);

int main(void)
{
	POLY *X = oneTerm(1, 1.0);
	POLY *One = oneTerm(0, 1.0);
	
	POLY *A = add(X, One);
	POLY *A2 = mply(A, A);
	POLY *A3 = mply(A2, A);
	POLY *A4 = mply(A3, A);
	POLY *A5 = mply(A4, A);
	
	printf("A = ");
	print(A);
	printf("A2 = ");
	print(A2);

	POLY *B = sub(X, One);
	POLY *B2 = mply(B, B);
	POLY *B3 = mply(B2, B);
	POLY *B4 = mply(B3, B);
	POLY *B5 = mply(B4, B);
	
	POLY *C = add(A, B);
	POLY *C2 = mply(A2, B2);
	POLY *C3 = mply(A3, B3);
	POLY *C4 = mply(A4, B4);
	POLY *C5 = mply(A5, B5);

	printf("C = ");
	print(C);
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

/* 
 * oneTerm():
 * This function creates a 1-term polynomial of the form coef x X^degree and returns the new polynomial.
 */
POLY *oneTerm(int degree, double coef)
{
	POLY *new_term = malloc(sizeof(POLY));
	
	new_term->degree = degree;
	new_term->coef = coef;
	new_term->next = NULL;
	
	return new_term;
}

/* 
 * add():
 * This function adds two polynomials p1 and p2 to form a new polynomial and return the new polynomial.
 */
POLY *add(POLY *p1, POLY *p2)
{
	POLY *new_poly = NULL;
	POLY *cur_term = NULL;
	POLY *pre_term = NULL;
	
	for(; p1 != NULL; p1 = p1->next) {
		if (new_poly == NULL) {
			//printf("add: insert Node\n");
			new_poly = oneTerm(p1->degree, p1->coef);
			cur_term = new_poly;
		} else {
			//printf("add: insert Node\n");
			cur_term->next = oneTerm(p1->degree, p1->coef);
			cur_term = cur_term->next;
		}
	}
	for(; p2 != NULL; p2 = p2->next) {
		pre_term = NULL;
		for(cur_term = new_poly; cur_term != NULL; pre_term = cur_term, cur_term = cur_term->next) {
			if (p2->degree == cur_term->degree) {
				//printf("add: sum Node\n");
				cur_term->coef += p2->coef;
				if (cur_term->coef == 0.0) {
				  //printf("add: delete Node\n");
				  if (pre_term == NULL) {
					new_poly = new_poly->next;
					free(cur_term);
				  } else {
					pre_term->next = cur_term->next;
					free(cur_term);
				  }
				}
				break;
			}
		}
		if (cur_term == NULL) {
			pre_term = NULL;
			for(cur_term = new_poly; cur_term != NULL; pre_term = cur_term, cur_term = cur_term->next) {
				if (p2->degree > cur_term->degree) {
					if (pre_term == NULL) {
						//printf("add: insert Node at start position\n");
						new_poly = oneTerm(p2->degree, p2->coef);
						new_poly->next = cur_term;
					} else {
						//printf("add: insert Node at middle position\n");
						pre_term->next = oneTerm(p2->degree, p2->coef);
						pre_term->next->next = cur_term;
					}
					break;
				}
			}
			if (cur_term == NULL) {
				//printf("add: insert Node at end position\n");
				pre_term->next = oneTerm(p2->degree, p2->coef);
			}
		}
	}
	
	return new_poly;
}


/* 
 * sub():
 * This function subtract polynomial p2 from p1 to form a new polynomial and return the new polynomial.
 * add function is utilized to implement this function.
 */
POLY *sub(POLY *p1, POLY *p2)
{
	POLY *new_poly = NULL;
	POLY *cur_term_p2 = NULL;
	
	cur_term_p2 = p2;
	for(; cur_term_p2 != NULL; cur_term_p2 = cur_term_p2->next) {
		cur_term_p2->coef = -cur_term_p2->coef;
	}
	new_poly = add(p1, p2);
	
	cur_term_p2 = p2;
	for(; cur_term_p2 != NULL; cur_term_p2 = cur_term_p2->next) {
		cur_term_p2->coef = -cur_term_p2->coef;
	}
	
	return new_poly;
}

/* 
 * mply():
 * This function multiplies two polynomials p1 and p2 to form a new polynomial and return the new polynomial.
 */
POLY *mply(POLY *p1, POLY *p2)
{
	POLY *new_poly = NULL;
	POLY *cur_term = NULL;
	POLY *pre_term = NULL;
	POLY *cur_term_p2 = NULL;
	
	for(; p1 != NULL; p1 = p1->next) {
		cur_term_p2 = p2;
		for(; cur_term_p2 != NULL; cur_term_p2 = cur_term_p2->next) {
			if (new_poly == NULL) {
				//printf("mply: insert Node\n");
				new_poly = oneTerm(p1->degree + cur_term_p2->degree, p1->coef * cur_term_p2->coef);
			} else {
				
				pre_term = NULL;
				for(cur_term = new_poly; cur_term != NULL; pre_term = cur_term, cur_term = cur_term->next) {
					if ( (p1->degree + cur_term_p2->degree) == cur_term->degree) {
						//printf("mply: sum Node\n");
						cur_term->coef += (p1->coef * cur_term_p2->coef);
						if (cur_term->coef == 0.0) {
							//printf("mply: delete Node\n");
							if (pre_term == NULL) {
								new_poly = new_poly->next;
								free(cur_term);
							} else {
								pre_term->next = cur_term->next;
								free(cur_term);
							}
						}
						break;
					}
				}
				
				if (cur_term == NULL) {
					pre_term = NULL;
					for(cur_term = new_poly; cur_term != NULL; pre_term = cur_term, cur_term = cur_term->next) {
						if ((p1->degree + cur_term_p2->degree) > cur_term->degree) {
							if (pre_term == NULL) {
								//printf("mply: insert Node at start position\n");
								new_poly = oneTerm(p1->degree + cur_term_p2->degree, p1->coef * cur_term_p2->coef);
								new_poly->next = cur_term;
							} else {
								//printf("mply: insert Node at middle position\n");
								pre_term->next = oneTerm(p1->degree + cur_term_p2->degree, p1->coef * cur_term_p2->coef);
								pre_term->next->next = cur_term;
							}
							break;
						}
					}
					if (cur_term == NULL) {
						//printf("mply: insert Node at end position\n");
						pre_term->next = oneTerm(p1->degree + cur_term_p2->degree, p1->coef * cur_term_p2->coef);
					}
				}
				
			}
			
		}
	}

	return new_poly;
}

/* 
 * release():
 * This function releases all nodes of the polynomial p1 and returns them to the heap space.
 */
void release(POLY *p1)
{
	if (p1->next == NULL) {
		free(p1);
	} else {
		release(p1->next);
		free(p1);
	}
}

/* 
 * print():
 * This function prints out the polynomial p1 in human readable form.
 */
void print(POLY *p1)
{	
	if (p1->degree == 0) {
		printf("%g", p1->coef);
	} else if (p1->degree == 1) {
		if (p1->coef == 1.0) { 
			printf("x");
		} else if (p1->coef == -1.0) {
			printf("-x");
		} else {
			printf("%g x", p1->coef);
		}
	} else {
		if (p1->coef == 1.0) {
			printf("x^%d", p1->degree);
		} else if (p1->coef == -1.0) {
			printf("-x^%d", p1->degree);
		} else {
			printf("%g x^%d", p1->coef, p1->degree);
		}
	}
	p1 = p1->next;

	for(; p1 != NULL; p1 = p1->next)
	{
		if (p1->degree == 0) {
			printf(" %+g", p1->coef);
		} else if (p1->degree == 1) {
			if (p1->coef == 1.0) { 
				printf(" +x");
			} else if (p1->coef == -1.0) {
				printf(" -x");
			} else {
				printf(" %+g x", p1->coef);
			}
		} else {
			if (p1->coef == 1.0) { 
				printf(" +x^%d", p1->degree);
			} else if (p1->coef == -1.0) {
				printf(" -x^%d", p1->degree);
			} else {
				printf(" %+g x^%d", p1->coef, p1->degree);
			}
		}
	}
	printf("\n");
}
