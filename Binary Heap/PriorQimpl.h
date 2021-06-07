PQ* PQinit(int x)
{
	PQ *p;
	empl e;
	e.salary=-10;
    p=(PQ*)malloc(sizeof(PQ));
	p->cap=x;
	p->size=0;
	p->a[0]=e;
	return p;
}
PQ* PQinsert(PQ *p,empl x)
{
	int i;
	empl temp;
	if(p->size==p->cap)
	{
		printf("Queue is Full\n");
		return NULL;
	}
    i=++p->size;
	p->a[i]=x;
	while(p->a[i/2].salary > x.salary){
		temp=p->a[i];
		p->a[i]=p->a[i/2];
		p->a[i/2]=x;
	}
	return p;
}

empl getempl()
{
	empl e;
	printf("Name   : ");
	scanf("%s",e.name);
	printf("Id     : ");
	scanf("%d",&e.id);
	printf("Salary : ");
	scanf("%f",&e.salary);
	return e;
}

PQ* PQdelete(PQ *p)
{
	if(p->size==0)
	{
		printf("Heap is Empty\n");
		return NULL;
	}
	/*for(i=1;(i *2)<=p->size;i=child)
	{
	child=i*2;
	if(p->a[child+1].salary < p->a[child].salary)
		child++;
	if(lastelement.salary > p->a[child].salary)
		p->a[i]=p->a[child];
	else
		break;
	}
	p->a[i]=lastelement;*/

	int i=1,child;
	empl minelement, lastelement;
	minelement=p->a[1];
	lastelement=p->a[p->size];
	p->size--; //as we are deleting one element

    while(2*i<=p->size)
    {
        child=2*i;
        if(p->a[child+1].salary<p->a[child].salary) //go to the least child
            child++;
        if(lastelement.salary>p->a[child].salary)
            p->a[i]=p->a[child];
        else
            break;
        i=child;
    }
    p->a[i]=lastelement; //replace lastelement to the correct pos after deleting
	disp(minelement,0);
	return p;
}
void PQdisplay(PQ *p,int index,int tab)
{
	int i;

	if(index<=p->size)
	{
		disp(p->a[index],tab);
		printf("\n");
		if(index*2<=p->size)
		PQdisplay(p,index*2,tab+1);
		if(index*2+1<=p->size)
		PQdisplay(p,index*2+1,tab+1);
	}
}

void disp(empl e,int tab)
{
	int i;
	for(i=0;i<tab;i++)
        printf("\t");
	printf("_____________\n");
	for(i=0;i<tab;i++)
        printf("\t");
	printf("Name   : %s\n",e.name);
	for(i=0;i<tab;i++)
        printf("\t");
	printf("Id     : %d\n",e.id);
	for(i=0;i<tab;i++)
        printf("\t");
	printf("Salary : %.2f\n",e.salary);
	for(i=0;i<tab;i++)
        printf("\t");
	printf("_____________\n\n");
}
