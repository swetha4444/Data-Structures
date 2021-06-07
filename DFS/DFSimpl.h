#include<stdio.h>
#include<string.h>
#include<stdlib.h>

stack* initialize(int x)
{
	stack *s;
	s=(stack*)malloc(sizeof(stack));
	s->top=-1;
	s->size=x;
	return s;
}

int isfull(stack *s)
{
	if(s->top==s->size-1)
		return 1;
	return 0;
}
int isempty(stack *s)
{
	if(s->top==-1)
		return 1;
	return 0;
}
void push(stack *q,int x)
{
	if(isfull(q))
	{
		printf("Stack is full\n");
		return;
	}
	q->a[++q->top]=x;
}
int pop(stack *q)
{
	if(isempty(q))
	{
		printf("Stack is empty\n");
		return -1;
	}
	return q->a[--q->top];
}
int peek(stack *s)
{
	if(isempty(s))
	{
		printf("Stack is empty\n");
		return -1;
	}
	return s->a[s->top];
}

/***********Adjacency Matrix**********/
int checkpresence(cityADT *c,char s[])
{
	int i;
	for(i=0;i<c->n;i++)
	{
		if(strcmp(s,c->a[i])==0)
		return i;
	}
	return -1;
}

cityADT* create(cityADT *c)
{
	c=(cityADT*) malloc(sizeof(cityADT));
	int i,j,k,x;
	char from[20],to[20];

	printf("\nEnter the number of cities:");
	scanf("%d",&c->n);

	printf("\nEnter the city names:\n");
	for(k=0;k<c->n;k++)
	{
		scanf(" %s",c->a[k]);
		c->vs[k]=0;
	}
	
	for(i=0;i<c->n;i++)
	{
		for(j=0;j<c->n;j++)
			c->m[i][j]=0;
	}

	char ch='y';

	while(ch=='y')
	{
		printf("\nFrom:");
		scanf("%s",from);
		printf("To:");
		scanf("%s",to);

		i=checkpresence(c,from);
		j=checkpresence(c,to);

		c->m[i][j]+=1;
		printf("Connection successfully added");

		printf("\nDo you want to continue the connections? (y/n) ");
		scanf(" %c", &ch);
	}
	
	return c;
}

void display(cityADT *c)
{
	int i,j;

	for(i=0;i<c->n;i++)
	{
		for(j=0;j<c->n;j++)
		{
			printf("%d  ",c->m[i][j]);
		}
		printf("\n");
	}

	printf("\nConnections:\n");
	for(i=0;i<c->n;i++)
	{
		for(j=0;j<c->n;j++)
		{
			if(c->m[i][j]==1)
				printf("From %s to %s.\n",c->a[i],c->a[j]);
		}
		printf("\n");
	}
}

/*********DFS code**********/
void visit(cityADT *c,int x)
{
	c->vs[x]=1;
	//printf("%s\t",c->a[x]);
}
void reset(cityADT *c)
{
	int j;
	for(j=0;j<c->n;j++)
	{
		c->vs[j]=0;
	}
}
int unvisited(cityADT *c)
{
	int i;
	for(i=0;i<c->n;i++)
	{
		if(c->vs[i]==0)
		return i;
	}
	return -1;
}
int unvisitedNeighbour(cityADT *c,int x)
{
	int i;
	for(i=0;i<c->n;i++)
	{
		if(c->vs[i]==0&&c->m[x][i]==1)
		return i;
	}
	return -1;
}	
void DFS(cityADT* c)
{
	stack *s;
	int x,y,z;
	int i;
	s=initialize(c->n);
	while(unvisited(c)!=-1)
	{
		x=unvisited(c);
		visit(c,x);
		push(s,x);
		while(isempty(s))
		{
			z=peek(s);
			if(unvisitedNeighbour(c,z)!=-1)
			{	
				y=unvisitedNeighbour(c,z);
				visit(c,y);
				push(s,y);
			}
			else
			{
				i=pop(s);
			}
		}
		printf("\n");
	}
	reset(c);
}
void checkConnectivity(cityADT *c,char s[100],char d[100]) 
{
  	stack *S;    int x, z, y;
	int i=0,j=0,k=0;
	S=initialize(c->n);
	x=checkpresence(c,s);
	if(x==-1)
	{
		printf("no match for source\n");
		return;
	}
	else
	{		
		printf("source found \n");
	}
	c->vs[x]=1;
	printf("%s\n",c->a[x]);	
	push(S,x);
	while (!isempty(S)&&j==0)
	{
		z = peek(S); 
		if(unvisitedNeighbour(c,z)!=-1&&j==0)
		{	
			y=unvisitedNeighbour(c,z);
			c->vs[y]=1;
			printf("%s\n",c->a[y]);			
			if(!strcmp(c->a[y],d))
			{
				j=1;
			}
			push(S,y); 
		}
		else
		{
			i=pop(S);
		}
	}
	if(j==0)
	{
		printf("Connection not present\n");
	}
	reset(c);
}

				





