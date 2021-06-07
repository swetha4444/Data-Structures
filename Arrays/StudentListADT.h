#include<stdio.h>
#include<string.h>
#define max 10

void display(Student l){
    printf("\n");
    printf("Name: %s\n",l.Name);
    printf("Regno: %d\n",l.RegNo);
    printf("Marks:\n");
    printf("%d\t%d\t%d\n",l.mark1,l.mark2,l.mark3);
    printf("Result: %c",l.Result);
    }

void insertFront(struct listADT *l,Student s){
    int i;
	if(l->size==0) l->a[l->size]=s;
	else if(l->size>max) printf("Can't insert.");
	else{
		for(i=(l->size-1);i>=0;i--) l->a[i+1]=l->a[i];
		l->a[0]=s;
	     }
	l->size++;}

void insertEnd(struct listADT *l,Student s){
    l->a[l->size]=s;
	l->size++;}

void insertRegNo(struct listADT *l,Student s, int regno){
    int i,j,flag=0;
    for(i=0;i<l->size;i++){
        if(l->a[i].RegNo==regno){
            for(j=l->size-1;j>=(i+1);j--) l->a[j+1]=l->a[j];
            l->a[i+1]=s;
            l->size++;
            flag++;
            break;
            }
        }
    if(flag==0) printf("\nStudent details not found");

    }

Student searchRegno(struct listADT l, int regno){
    int i,flag=0;
    for(i=0;i<l.size;i++)
    {
        if(l.a[i].RegNo==regno)
            {
                flag++;
                return l.a[i];
                break;
            }
    }
    if(flag==0) printf("NO SEARCH HISTORY");

  }

Student* searchName(struct listADT l,char name[]){
	Student temp[10];
	int i,c=0;
	for(i=0;i<l.size;i++){
		if(strcmp(l.a[i].Name,name)==0){
			temp[c]=l.a[i];
			c++;
		  }
	}

	for(i=0;i<c;i++) display(temp[i]);
	return temp;
  }

void computeResult(struct listADT *l){
    int i;
	for(i=0;i<l->size;i++){
        l->a[i].Total=l->a[i].mark1+l->a[i].mark2+l->a[i].mark3;
		if(l->a[i].mark1>=50 && l->a[i].mark2>=50 && l->a[i].mark3>=50) l->a[i].Result='P';
		else l->a[i].Result='F';
      }
  }
Student* listResult(struct listADT l){

	Student temp[100];
	int c=0,i;
	for(i=0;i<l.size;i++)
    {
		if(l.a[i].Result='P')
		{
			temp[c]=l.a[i];
			c=c+1;
		}
    }
    for(i=0;i<c;i++)
        display(temp[i]);

    return temp;
}

void delete(struct listADT *l, int regNum){
	int i,j,f=0;
	for(i=0;i<l->size;i++){
		if(l->a[i].RegNo==regNum){
            f=1;
			for(j=i+1;j<l->size;j++)
				l->a[j-1]=l->a[j];
        else f=0;
		}
    if(f==0) printf("RegNo not found");
	}
	l->size--;
}














