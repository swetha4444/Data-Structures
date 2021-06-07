#include<stdio.h>
#include<string.h>

/**************Queue Implementation************/
queue* initialize(int s)
{
	queue *q;
	q=(queue*)malloc(sizeof(queue));
	q->f=0;
	q->r=0;
	q->size=s+1;
	return q;
}

int isFull(queue *q)
{
	if(((q->r==q->size-1)&&(q->f==0))||(q->r+1==q->f))
	return 1;
	return 0;
}

int isEmpty(queue *q)
{
	if(q->r==q->f)
	return 1;
	return 0;
}

void enqueue(queue *q,int x)
{
	if(isFull(q))
	{
		printf("queue is full\n");
		return;
	}
	q->a[q->r]=x;
	q->r=(q->r+1)%q->size;
}

int dequeue(queue *q)
{
	if(isEmpty(q))
	{
		printf("queue is empty\n");
		return -1;
	}
	int x=q->f;
	q->f=(x+1)%q->size;
	return q->a[x];
}

/********************Adjacency Matrix Creation********************/

int searchIndex(cityADT *c,char *str)
{
	int i;

	for(i=1;i<=c->city;i++)
	{
		if(strcmp(str,c->names[i])==0)
			return i;
	}
	return 0;
}

void create(cityADT *c)
{

	int i,j,k,x;
	char from[20],to[20];
	c->con=0;
	//c->adj={0};

	printf("\nEnter the number of cities:");
	scanf("%d",&c->city);

	printf("\nEnter the city names:\n");
	for(k=1;k<=c->city;k++)
	{
		scanf("%s",c->names[k]);
	}

	char ch='y';

	while(ch=='y')
	{
		printf("\nFrom:");
		scanf("%s",from);
		printf("To:");
		scanf("%s",to);

		i=searchIndex(c,from);
		j=searchIndex(c,to);

		c->adj[i][j]+=1;
		printf("Connection successfully added");
		c->con++;

		printf("\nDo you want to continue the connections? (y/n) ");
		scanf(" %c", &ch);
	}
}

void display(cityADT *c)
{
	int i,j,n;
	n=c->city;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d  ",c->adj[i][j]);
		}
		printf("\n");
	}

	printf("\nConnections:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(c->adj[i][j]==1)
				printf("From %s to %s.\n",c->names[i],c->names[j]);
		}
		printf("\n");
	}
}

/**************************BFS Implementation*******************************/

void visit(cityADT *c,int index)
{
	c->visit[index]=1;
    printf("%s",c->names[index]);
}

int unvisited(cityADT *c)
{
	int i;
	for(i=0;i<c->city;i++)
	{
		if(c->visit[i]==0)
			return i;
	}
	return -1;
}

int unvisitedNeighbours(cityADT *c,int x)
{
    int i;
    for(i=0;i<c->city;i++)
    {
        if(c->visit[i]==0&&(c->adj[x][i]>0))
            return i;
    }
    return -1;
}

void reset(cityADT *c)
{
    int j;
	for(j=0;j<c->city;j++)
	{
		c->visit[j]=0;
	}
    printf("RESET VISIT\n");
}

void BFS (cityADT *c)
{
    queue *Q;
    int i;
  	Q=initialize(c->city);
    int x,y,z;

    while(unvisited(c)!=-1)
    {
        x=unvisited(c);
        visit(c,x);
        enqueue(Q,x);
        while(!isEmpty(Q))
        {
            z=dequeue(Q);

            while(unvisitedNeighbours(c,z)!=-1)
            {
               y=unvisitedNeighbours(c,z);
               visit(c,y);
               enqueue(Q,y);
            }
        }
        printf("\n");
    }
    reset(c);
}

int checkConnectivity(cityADT *c,char s[100],char d[100])
{
  	queue *q;
  	int x, z, y;
  	q=initialize(c->city);

	for(x=0;x<c->city;x++)
	{
		if(!strcmp(s,c->names[x]))
		break;
	}

	if(x==c->city)
	{
		printf("No match for source\n");
		return 0;
	}
	else
	{
		printf("Source found \n");
	}

	c->visit[x]=1;
	enqueue(q,x);

	if (!isEmpty(q))
	{
		z = dequeue(q);
		while(unvisitedNeighbours(c,z)!=-1)
		{
			y=unvisitedNeighbours(c,z); //returns unvisited neighbour's index
			c->visit[y]=1;
			if(!strcmp(c->names[y],d))
			{
			    reset(c);
				return 1;
			}
			enqueue(q,y);
		}
	}
	reset(c);
    return 0;
}
