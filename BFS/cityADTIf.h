typedef struct
{
	int adj[20][20];
	int city,con; //no. of cities and iteration of no. of connections
	char names[20][20]; //array of all city names
	int visit[50];

}cityADT;

typedef struct
{
	int a[100];
	int size,f,r;
}queue;

queue* initialize(int s);
int isFull(queue *q);
int isEmpty(queue *q);
void enqueue(queue *q,int x);
int dequeue(queue *q);

void create(cityADT *c);
int searchIndex(cityADT *c,char *str);
void display(cityADT *c);

void visit(cityADT *c,int index);
int unvisited(cityADT *c);
int unvisitedNeighbours(cityADT *c,int x);
void reset(cityADT *c);
void BFS (cityADT *c);
int checkConnectivity(cityADT *c,char s[100],char d[100]);

