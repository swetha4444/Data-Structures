#include<stdio.h>
#define max 10
typedef struct{
	int RegNo;
	char Name[20],Result;
	int mark1,mark2,mark3,Total;
       }Student;

struct listADT{
	int size;
	Student a[max];};

void display(Student l);
void insertFront(struct listADT* l,Student s);
void insertEnd(struct listADT* l,Student s);
void insertRegNo(struct listADT *l,Student s, int regno);
Student searchRegno(struct listADT l, int regno);
Student* searchName(struct listADT l,char name[20]);
void computeResult(struct listADT *l);
Student* listResult(struct listADT l);
void delete(struct listADT *l, int regNum);
