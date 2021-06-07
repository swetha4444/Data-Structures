#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int id;
	char name[30];
	float salary;
}empl;

typedef struct
{
	empl a[100];
	int cap,size;
}PQ;

PQ* PQinit(int x);
PQ* PQinsert(PQ *p,empl x);
PQ* PQdelete(PQ *p);
void PQdisplay(PQ *p,int index,int tab);
