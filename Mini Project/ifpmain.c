#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ifpif.h"
#include"ifpbst.h"

char adP[10]="1000";
int adm=1;
//int time = 0;

void adminMenu(CSE_BSTnode *P)
{
    system("cls");
    int ch;
    printf("WELCOME ADMIN!\n");
    printf("\n Password     : ");
    int i=0,f=0;
    char c, pass[10];
        do
        {
            c=getch();
            pass[i]=c;
            if(c!='\r')
            {
                printf("*");
                i++;
            }
            else
            {
                pass[i]='\0';
                break;
            }
        }while(c!='\r');
        if(strcmp(adP,pass)!=0)
                    f=1;
        if(f==1)
            return;
        system("cls");

    do
    {
        printf("Enter choice \n [1]View students registered\n [2]Exit\nEnter choice: ");
        scanf("%d",&ch);

        if(P==NULL) {
                printf("P is NULL\n"); ch=2;}
        if(ch==3)
        {
            time=1;
            printf("%d",time);
            P=admission(P);
            printf("admin add success");
        }

        else if(ch==1)
        {
            //printf("hi");
            Status(P);
            dispTree(P,0);
        }
    }while(ch!=2);

}

void login(CSE_BSTnode *b)
{
	char e[50],f[20],c;
	int i,m,k;
	studentDetails found;
	us:
	system("cls");
	printf("\n\n USER LOGIN\n\n\n");
	printf(" Name\t: ");
	scanf(" %s",e);
	printf(" \nCutoff\t: ");
	scanf("%d",&m);
	printf("\n Password\t: ");
	i=0;
	do
	{
		c=getch();
		f[i]=c;
		if(c!='\r')
		{
			printf("*");
			i++;
		}
		else
		{
			f[i]='\0';
			break;
		}
	}while(c!='\r');
    printf("Password entered: %s",f);
	found=findPassword(b,e,m);
	k=strcmp(found.password,f);
	//printf("found pass %s\n",found.password);
	//printf("k= %d\n",k);

	if(k!=0)
	{
        printf("\n\n\n Invalid User\n\n\n");
        printf("\n Press enter to try again\n");
        getch();
        goto us;
	}
	else
	{
		printf("\n\n\n Login sucessful\n\n\n");
		printf("\n Press enter to continue\n\n\n");
		//getchar();
		//printf("CALL LOGIN MENU");
	}

	//menu(found.admno);
}



CSE_BSTnode *signUp(CSE_BSTnode *P,studentDetails s)
{
	system("cls");
	int i;
	char c;
	if(time==0)
    {
        printf("\n\n REGISTER \n\n");
        printf("\n Enter Name   : ");
        scanf(" %s",s.name);
        //printf("\n Gender (Male/Female)   : ");
        //scanf("%s",s.gender);

        printf("\n Password     : ");
        i=0;
        do
        {
            c=getch();
            s.password[i]=c;
            if(c!='\r')
            {
                printf("*");
                i++;
            }
            else
            {
                s.password[i]='\0';
                break;
            }
        }while(c!='\r');

        printf("\n\n Your admin no. is: %d",adm);
        s.admno=adm;
        adm++;

	//printf("\n\n DOB              : ");
	//scanf(" %s",s.dob);
	//printf("\n Address:     : ");
	//scanf(" %s",s.address);
	//printf("\n Contact   : ");
	//scanf("%s",s.contact);
	printf("\n\n Cutoff\t: ");
	scanf("%d",&s.cut_off);
	//printf("\n Board   : ");
	//scanf("%s",s.board);
	//printf("\n\n Nationality   : ");
	//scanf("%s",s.nationality);
    //printf("ADMISSION FILE");
	//admissionFile(s);
	//printf ("CALLING INSERT");
    P=insert(P,s);
    dispTree(P,0);
    return P;
    }
    else
        printf ("REGISTRATIONS CLOSED");
}


void studentloginMenu(CSE_BSTnode *P)
{
    int ch,amo,m;
    do{
    printf("\n\t\t\t\tWELCOME STUDENT!\n");
    printf("\nEnter your choice: \n [1]Cancel registration\n [2]Check status\n [3]Exit\n");
    scanf("%d",&ch);

    if(ch==1)
    {

    printf("Enter admission number: ");
    scanf("%d",&amo);
    printf("Enter cutoff: ");
    scanf("%d",&m);
    P=Cancellation(P,amo,m);
    }

    else if(ch==2)
    {
        int a,m;
        printf("Enter admission number: ");
        scanf("%d",&a);
        printf("Enter cutoff: ");
        scanf("%d",&m);

        printf("Your waiting list number: ");
        ctr=1;
        Status(P);
        showAdmission(P,a,m);

    }

    //system("cls");
    }while(ch!=3);
}


CSE_BSTnode *studentMainMenu(CSE_BSTnode *P)
{
	studentDetails s;
	int t;
	bbs:
	system("cls");
	printf("\n [1] Register\n");
	printf("\n [2] Login\n");
	printf("\n [3] Exit\n");
	printf("\n\n Choice : ");
	scanf("%d",&t);

	switch(t)
	{
		case 1:P=signUp(P,s);goto bbs;break;
		case 2:login(P);system("cls");studentloginMenu(P);break;
		case 3:system("cls");break;

		default:
		{
			printf("\n Invalid choice");
			printf("\n\n Press enter to try again");
			getchar();
			goto bbs;
		}
	}
	return P;
}

void main(){
    	CSE_BSTnode *P=NULL;
    	int ch;

    	maintag:
        system("cls");
    	printf("WELCOME TO SSN COLLEGE OF COMPUTER SCIENCE!\nLogin As:\n [1]Admin\n [2]Student\n [3]Exit\nEnter your choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            adminMenu(P);
            goto maintag;
        }
        else if(ch==2)
        {
            P=studentMainMenu(P);
            goto maintag;
        }
        else if(ch==3)
        {
           exit(1);
        }
        else
        {
            printf("Invalid Input");
        }
}

