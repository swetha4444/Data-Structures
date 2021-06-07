#include<stdio.h>
#include"proto.h"
#include"StudentListADT.h"
struct listADT l;

 void main(){
    int i,ch;
    char name[10];
    int r;

    printf("Enter no of students:\n");
    scanf("%d",&l.size);
    for(int i=0;i<l.size;i++)
    {
    printf("Enter name: ");
    scanf(" %[^\n]s",l.a[i].Name);
    printf("Enter Regno: ");
    scanf("%d",&l.a[i].RegNo);
    printf("Enter 3 marks: ");
    scanf("%d %d %d",&l.a[i].mark1,&l.a[i].mark2,&l.a[i].mark3);
    }

    printf("\nMENU:\n1.Insert Front\n2.Insert End\n3.Insert per RegNo\n4.Search per RegNo.\n5.Search per Name\n6.List result\n7.Delete\n8.Display\n");
    printf("Enter choice:");
    scanf("%d",&ch);

    do{
        char name[10];
        int r;
        Student s,s1,s2,found,*nSearch,*res;

    if(ch==1){
    printf("\nInsert Front:");
    printf("\nEnter name: ");
    scanf(" %[^\n]s",s.Name);
    printf("Enter Regno: ");
    scanf("%d",&s.RegNo);
    printf("Enter 3 marks: ");
    scanf("%d %d %d",&s.mark1,&s.mark2,&s.mark3);
    insertFront(&l,s);}

    else if(ch==2){
    printf("\nInsert End:");
    printf("\nEnter name: ");
    scanf(" %[^\n]s",s1.Name);
    printf("Enter Regno: ");
    scanf("%d",&s1.RegNo);
    printf("Enter 3 marks: ");
    scanf("%d %d %d",&s1.mark1,&s1.mark2,&s1.mark3);
    insertEnd(&l,s1);}

    else if(ch==3){
    printf("\nInsert per reg no\nEnter Reg No.: ");
    scanf("%d",&r);
    printf("\nEnter structure details: ");
    printf("\nEnter name: ");
    scanf(" %[^\n]s",s2.Name);
    printf("Enter Regno: ");
    scanf("%d",&s2.RegNo);
    printf("Enter 3 marks: ");
    scanf("%d %d %d",&s2.mark1,&s2.mark2,&s2.mark3);
    insertRegNo(&l,s2,r);}

    else if(ch==4){
    printf("\nSearch with RegNo: \nEnter RegNo: ");
    scanf("%d",&r);
    found= searchRegno(l,r);
    display(found);}

    else if(ch==5){
    printf("\nSearch by name\nEnter name: ");
    scanf(" %[^\n]",name);
    i=0;
    nSearch=searchName(l,name);}

    else if(ch==6){
    computeResult(&l);
    printf("\nPASSED STUDENTS: \n");
    res=listResult(l);}

    else if(ch==7){
    printf("\nDelete with RegNo: \nEnter RegNo: ");
    scanf("%d",&r);
    delete(&l,r);}

    else if(ch==8){
    printf("\nSTUDENT DETAILS:\n");
    for(i=0;i<l.size;i++) display(l.a[i]);}

    printf("\nEnter choice again: ");
    scanf("%d",&ch);

    }while(ch!=9);

 }

/*OUTPUT:
Enter no of students:
1
Enter name: Swetha
Enter Regno: 183
Enter 3 marks: 100 100 100

MENU:
1.Insert Front
2.Insert End
3.Insert per RegNo
4.Search per RegNo.
5.Search per Name
6.List result
7.Delete
8.Display
Enter choice:1

Insert Front:
Enter name: Tarun
Enter Regno: 184
Enter 3 marks: 90 67 65

Enter choice again: 2

Insert End:
Enter name: Dheepika
Enter Regno: 160
Enter 3 marks: 98 67 54

Enter choice again: 3

Insert per reg no
Enter Reg No.: 184

Enter structure details:
Enter name: Sriram
Enter Regno: 101
Enter 3 marks: 100 100 100

Enter choice again: 6

PASSED STUDENTS:

Name: Tarun
Regno: 184
Marks:
90      67      65
Result: P
Name: Sriram
Regno: 101
Marks:
100     100     100
Result: P
Name: Swetha
Regno: 183
Marks:
100     100     100
Result: P
Name: Dheepika
Regno: 160
Marks:
98      67      54
Result: P
Enter choice again: 4

Search with RegNo:
Enter RegNo: 183

Name: Swetha
Regno: 183
Marks:
100     100     100
Result: P
Enter choice again: 5

Search by name
Enter name: Tarun

Name: Tarun
Regno: 184
Marks:
90      67      65
Result: P
Enter choice again: 7

Delete with RegNo:
Enter RegNo: 160

Enter choice again: 8

STUDENT DETAILS:

Name: Tarun
Regno: 184
Marks:
90      67      65
Result: P
Name: Sriram
Regno: 101
Marks:
100     100     100
Result: P
Name: Swetha
Regno: 183
Marks:
100     100     100
Result: P
Enter choice again: 7

Delete with RegNo:
Enter RegNo: 12
RegNo not found
*/
