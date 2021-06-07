int time=0;

//LIST FUNCTIONS

int isFull(Samecut_list *l)
{
	if(l->size==l->cap)
		return 1;
	else
		return 0;
}

CSE_BSTnode *initialize(CSE_BSTnode *P)
{
	//printf("inside initialise\n");
	P=(CSE_BSTnode *)malloc(sizeof(CSE_BSTnode));
	P->lptr=NULL;
	P->rptr=NULL;
	return P;
}

Samecut_list *init(Samecut_list *l)
{
	//printf("inside init\n");
	l=(Samecut_list *)malloc(sizeof(Samecut_list));
	l->size=0;
	l->cap=5;
	return l;
}

Samecut_list *listinsert(Samecut_list *l,studentDetails a)
{
	//printf("inside listinsert\n");
	if(isFull(l)==1)
		printf("Capacity is full");
	else
	{
		l->arr[l->size]=a;
		//printf("%s",l->arr[0].name);
		//printf("%d inserted in list\n",l->arr[0].cut_off);
		//printf("\n%s %d",l->arr[1].name,l->arr[1].cut_off);
		l->size+=1;
	}

	printf("Inserted successfully\n");

	return l;
}

CSE_BSTnode *insert(CSE_BSTnode *P,studentDetails x)
{
	//printf("inside insert\n");

	if(P==NULL)
	{
		//printf("null\n");
		P=initialize(P);
		P->l=init(P->l);
		P->mark=x.cut_off;
		P->l=listinsert(P->l,x);
	}

	else
	{
		if(P->mark>x.cut_off)
		{
			//P->lptr=NULL;
			P->lptr=insert(P->lptr,x);
		}

		else if(P->mark<x.cut_off)
			P->rptr=insert(P->rptr,x);

		else if(P->mark==x.cut_off)
			P->l=listinsert(P->l,x);
	}

	return P;
}

void listdisplay(Samecut_list *l)
{
	//printf("inside list display");
	int i;
	for(i=0;i<l->size;i++)
	{
		printf("%s\t",l->arr[i].name);
		printf("%d\t%d\t;",l->arr[i].cut_off,l->arr[i].stat);
	}
}

void dispTree(CSE_BSTnode *P, int space)
{
   // printf("inside");
	//printf("%d",space);
	if(P==NULL)
		return;
	printf("\n");
	for (int i = 0; i < space; i++)
        printf("\t");
	listdisplay(P->l);

	if(P->rptr!=NULL)
        dispTree(P->rptr, space+1);

	if(P->lptr!=NULL)
        dispTree(P->lptr, space+1);
}


//APPLICATION FUNCTIONS
int ctr=1;
void Status(CSE_BSTnode *P)
{
    int i;
    if(P->rptr!=NULL)
      Status(P->rptr);
     //printf("\nName:%s	Role:%s		Runrate:%f\n", P->p.name,P->p.role,P->p.runrate);
    for(i=0;i<P->l->size;i++)
	{ //printf("status: %d",ctr);
		P->l->arr[i].stat=ctr;ctr++;}

	if(P->lptr!=NULL)
      Status(P->lptr);
}


//BST FUNCTIONS

CSE_BSTnode *findMin(CSE_BSTnode *P)
{
	printf("\ninside findmin\n");
	while(P->lptr)
		P=P->lptr;
	return P;
}

Samecut_list *cancel(Samecut_list *l,int ano)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		if(ano==l->arr[i].admno)
		{
			for(j=i;j<l->size;j++)
				{
					l->arr[j]=l->arr[j+1];

				}
				l->size--;
		}
		break;
	}
	return l;
}

CSE_BSTnode *Delete(CSE_BSTnode *P,int cut)
{
	//printf("inside delete");
	CSE_BSTnode *temp=initialize(temp);

	if(P->mark>cut)
		P->lptr=Delete(P->lptr,cut);
	else if(P->mark<cut)
		P->rptr=Delete(P->rptr,cut);
	else
	{
		if(P->lptr && P->rptr)
		{

			temp=findMin(P->rptr);
			P->mark=temp->mark;
			P->l=temp->l;
			P->rptr = Delete(P->rptr,cut);

		}
		else
		{
			temp=P;
			if(P->rptr==NULL)
				P=P->lptr;
			else if(P->lptr==NULL)
				P=P->rptr;
			free(temp);
		}
	}

	return P;

}

CSE_BSTnode *Cancellation(CSE_BSTnode *P,int ano,int cut)
{
	//printf("\ninside cancellation");

	CSE_BSTnode *temp=initialize(temp);
	if(P->mark>cut)
		P->lptr=Cancellation(P->lptr,ano,cut);
	else if(P->mark<cut)
		P->rptr=Cancellation(P->rptr,ano,cut);
	else //BSTnode of cut found
	{
		//printf("\ndelete node found");
		if(P->lptr && P->rptr)
		{
			P->l=cancel(P->l,ano);
			//printf("after cancel");
			//listdisplay(P->l);
			if(P->l->size==0)
			{
				temp=findMin(P->rptr);
				P->mark=temp->mark;
				P->l=temp->l;
		//		printf("\n%s",P->l->arr[0]);
				P->rptr = Delete(P->rptr,cut);//DELETE ENTIRE NODE
			}
		}
		else
		{
			P->l=cancel(P->l,ano);
			if(P->l->size==0)
			{
				temp=P;
				if(P->rptr==NULL)
					P=P->lptr;
				else if(P->lptr==NULL)
					P=P->rptr;
				free(temp);
			}
		}
	}
	return P;
}


//APPLICATION FUNCTIONS

studentDetails findPassword(CSE_BSTnode *P,char name[],int m)
{	int i;
	if(P->mark>m)
		return findPassword(P->lptr,name,m);
	if(P->mark<m)
		return findPassword(P->rptr,name,m);
    for(i=0;i<5;i++)
	{
		if(!strcmp(name,P->l->arr[i].name))
			return P->l->arr[i];
	}
}
int c=0;

CSE_BSTnode *admission(CSE_BSTnode *P)
{
	int i;
	printf("inside ad");
	printf("%d",P->l->size);
	if(P->rptr!=NULL)
		{printf("inide right");P=admission(P->rptr);}

	    //while(P->rptr!=NULL)
		 //return admission(P->rptr);
        printf("%d",P->l->size);
	    for(i=0;i<P->l->size;i++)
		{
		    printf("here");
			if(c<=3)
			{
				P->l->arr[i].stat=11;
				c++;
				printf("%d",P->l->arr[i].stat);

            }
			else
			{
				P->l->arr[i].stat=0;
				c++;
			}
			return P;
		}

		if(P->lptr!=NULL)
		 	{printf("inide left");P=admission(P->lptr);}

}

void showAdmission(CSE_BSTnode *P,int ano,int m)
{	int i;
if(time==1)
{

	for(i=0;i<P->l->size;i++)
	{
		if(P->l->arr[i].admno==ano){
			if(P->l->arr[i].stat==11){
				printf("Congratulations!");
				}
			else
				printf("Admission denied");
		}
	}

	if(P->mark > m)
		showAdmission(P->lptr,ano,m);
	if(P->mark < m)
		 showAdmission(P->rptr,ano,m);
}

else
{

    if(P->mark>m)
        showAdmission(P->lptr,ano,m);
    else if(P->mark<m)
        showAdmission(P->rptr,ano,m);
    else
        for(i=0;i<P->l->size;i++)
    {

        if(P->l->arr[i].admno==ano)
        {

            printf("%d",P->l->arr[i].stat);
        }
    }
}

}
/*
CSE_BSTnode *Search(CSE_BSTnode *P,char name[80])
{
	if(P==NULL)
		return NULL;
	else if(strcmp(P->p.name,name)>0)
		Search(P->lptr,name);
	else if(strcmp(P->p.name,name)<0)
		Search(P->rptr,name);
	else
		return P;
}
*/
