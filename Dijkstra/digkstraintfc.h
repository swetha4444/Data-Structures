#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int m[100][100];
	int n;
	int vs[100],dist[100];
	char a[100][100],path[100][100];
}cityADT;

cityADT* create(cityADT *c);
void disp(cityADT *c);
int unvisited(cityADT *c);
int unvisitedNeighbour(cityADT *c,int x);
void visit(cityADT *c,int x);
void reset(cityADT *c);
void Digkstra(cityADT *c,char s[100]);
void dispath(cityADT *c,char s[100],char d[100]);
void shortestPath(cityADT *c,char s[100],char d[100]);