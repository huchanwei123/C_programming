/*ee231002 lab10.word processing
    102061247, chan-wei hu
    date:5/5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LSTR 5000


int readLine(char para[LSTR]);				//function declarations
void lAlign(char *para);
void center(char *para);
void bAlign(char *para);
void print_line_for_c(const char *line);
void print_line_for_b(const char *line, int number_word);
int A;
int is_space(char ch);
char *p_spaces;

int main(int argc, char *argv[]){
    A=atoi(argv[1]);						//change the input number to integer
    char para[LSTR]={};

    while(readLine(para)==0){				//read in and do what we want to do
        if(strcmp(argv[2],"l")==0)			//if it's "l", get into lAlign function
            lAlign(para);
        if(strcmp(argv[2],"c")==0)			//if it's "c", get into center function
            center(para);
        if(strcmp(argv[2],"b")==0)			//if it's "b", get into bAlign function
            bAlign(para);
    }
    return 0;
}

int is_space(char ch){						//function to find if it is space
	if(ch=='\t' || ch==' '){
		return 1;
	}
	else return 0;
}

int readLine(char para[LSTR]){				//function used to read the line
    int ch, i=0, k=0;

    while((ch=getchar())!='\n'){			//start to read in
        para[k]=ch;
		k++;
    }
    para[k]='\0';										
    if(strcmp(para, "EOF")==0){
											//if read to "EOF", then stop
        i=1;
    }
    else i=0;
    return i;
}

void lAlign(char *para){					//function to put the line left
	char *p=para;							//variables declaration
	char word[A+1];
	char *pos=word;
	char line[A+1];
	line[0]='\0';
		
	if(!*p){
	  return;
	}
	while(*p){
	  while(is_space(*p)==1) p++;			//if it is space, then p++
	  while((is_space(*p)==0) && *p){		//if not, save p into pos and p++, pos++
	    *pos=*p;
	    pos++;
	    p++;
	  }
	  *pos='\0';
	  if(strlen(line)==0) {
	    strcat(line, word);					//cut the content of word into the end of line
	  } 
	  else{
	    if(A-strlen(line) > strlen(word)){	//if there are more positon to put the next word in, then put in
	      strcat(line, " ");				//cut the content of ' ' into the end of line
	      strcat(line, word);				//cut the content of word into the end of line
		} 
		else{
	      printf("%s\n", line);				//print out the line
		  line[0]='\0';
	      strcat(line, word);
		}
	  }
	  pos=word;
	  *pos='\0';
	}
	if(strlen(line) > 0){					//print out the line if it's length>0
		printf("%s\n", line);
	}
}

void center(char *para){					//function to put the story at middle
	char *p=para;							//variables declaration
    char word[A+1];
	char *pos=word;
    char line[A+1];
	line[0]='\0';
	
	if(!*p){
	  return;
	}
	while(*p){
	  while(is_space(*p)==1) p++;			//if it is space, then p++
	  while((is_space(*p)==0) && *p){		//if not, save p into pos and p++, pos++
        *pos=*p;
        pos++;
        p++;
	  }
      *pos='\0';
	  if(strlen(line)==0){					//cut the content of word into the end of line
	    strcat(line, word);
	  } 
	  else{
	    if(A-strlen(line) > strlen(word)){	//if there are more positon to put the next word in, then put in
	      	strcat(line, " ");				//cut the content of ' ' into the end of line
	      	strcat(line, word);				//cut the content of word into the end of line
		} 
		else{
	      	print_line_for_c(line);	//goto function print_line_for_c
		  	line[0]='\0';
	      	strcat(line, word);
		}
	  }
	  pos=word;
	  *pos='\0';
	}
	if(strlen(line) > 0){
        print_line_for_c(line);		//goto function print_line_for_c if it's length>-1
    }

}

void bAlign(char *para){					
	char *p=para;							//variables declaration
	int number_word;
    char word[A+1];
	char *pos=word;
    char line[A+1];
	line[0]='\0';
	
	if(!*p){
	  return;
	}
	while(*p){
	  while(is_space(*p)==1) p++;			//if it is space, then p++
	  while((is_space(*p)==0) && *p){		//if not, save p into pos and p++, pos++
        *pos=*p;
        pos++;
        p++;
	  }
      *pos='\0';
	  if (strlen(line)==0){
	    strcat(line, word);
		number_word++;						//count for words
	  } 
	  else{
	    if(A-strlen(line) > strlen(word)){	//if there are more positon to put the next word in, then put in
	      strcat(line, " ");				//cut the content of ' ' into the end of line
	      strcat(line, word);				//cut the content of word into the end of line
		  number_word++;
		} 
		else {
	      print_line_for_b(line, number_word);
											//goto function print_line_for_b
		  line[0]='\0';
		  number_word=0;
	      strcat(line, word);
		  number_word++;
		}
	  }
	  pos=word;
	  *pos='\0';
	}
	if(strlen(line) > 0){
        print_line_for_b(line, number_word);
											//goto function print_line_for_b
	}
}
void print_line_for_c(const char *line)
{
	char space[A+1];						//create an array	
	int space_left=(A-strlen(line))/2;		//if we want to put the paragraph at middle, then space_left and space_right have to be the same number
    int space_right=A-strlen(line)-space_left;
	int i;

  	for(i=0; i<A; i++){
    	space[i]=' ';						//let the array be an empty array
  	}
  	space[i]= '\0';							//end
  	p_spaces=space;							//assign space into p_space

    *(p_spaces+space_left) = '\0';			//p_spaces is a white space string
    	printf("%s", p_spaces);
    *(p_spaces+space_left) = ' ';
    	printf("%s", line);
    *(p_spaces+space_right) = '\0';
    	printf("%s\n", p_spaces);
    *(p_spaces+space_right) = ' ';
 
	return;
}
void print_line_for_b(const char *line, int number_word){
	
	int max_space=A-strlen(line);			//max_space is A minus the length of line
    int insert_space, i, j;					//variables declaration

    for(i=0; i<strlen(line); i++){			
         if(line[i] != ' ')
             putchar(line[i]);
         else{
             insert_space = max_space/(number_word-1);
											//the insert_space is the average of max_spcae 
             for(j=1; j<=insert_space+1; j++)
                 putchar(' ');
                 max_space -= insert_space;
                 number_word--;
             }
    }
    printf("\n");
    return;
}
