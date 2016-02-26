// header file for for lab11 Academic Competition

#define N 100                 // total number of students

typedef enum eSUBJ { math, phys, chem } SUBJ;

typedef struct sStudent {     // structure for each student
    char fName[20];           // first name
    char lName[20];           // last name
    int mathScore, physScore, chemScore;    // standard test scores
    SUBJ ap1;                 // AP1 subject
    int ap1Score;             // AP1 score
    SUBJ ap2;                 // AP2 subject
    int ap2Score;             // AP2 score
    int total;                // total score
    int winAAA;               // winner of Academic Achievement Award
} Student;

Student all[N];               // all students
