typedef struct
{
	int m[100][100];
	int n;
	int vs[100];
	char a[100][100];
}cityADT;
typedef struct 
{
	int a[100];
	int size,top;
}stack;

stack* initialize(int s);
int isfull(stack *q);
int isempty(stack *q);
void push(stack *q,int x);
int pop(stack *q);
int peek(stack *s);
int stacktime(stack *q);
cityADT* create(cityADT *c);
void disp(cityADT *c);
int unvisited(cityADT *c);
int unvisitedNeighbour(cityADT *c,int x);
void visit(cityADT *c,int x);
void reset(cityADT *c);
void DFS(cityADT *c);
void checkConnectivity(cityADT *c,char s[100],char d[100]);
