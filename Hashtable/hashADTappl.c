#include <stdio.h>
#include <stdlib.h>
#include "hashADTif.h"
#include "hashADTimpl.h"


void main()
{
	struct hash *h;
	h=(hashADT*)malloc(sizeof(hashADT));
	int size;
	printf("\nHASH ADT\n\nEnter size of hash table: ");
	scanf("%d",&size);
	init(h,size);
	int flag=0, choice;
	int x;
	while(flag==0)
	{
		printf("\nMENU\n1.Insert\n2.Find\n3.Display\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter element to append: ");
				scanf("%d",&x);
				insert(h,x);
				break;
			case 2:
				printf("Enter element to find: ");
				scanf("%d",&x);
				searchElement(h,x);
				break;
			case 3:
				display(h);
				break;
			case 4:
				printf("Exitting...\n");
				flag=1;
				break;
			default:
				printf("Enter valid choice");
		}
	}
}

/*
OUTPUT:

HASH ADT

Enter size of hash table: 10

MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 1
Enter element to append: 1
INSERTED 1 SUCESSFULLY

MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 1
Enter element to append: 2
INSERTED 2 SUCESSFULLY

MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 1
Enter element to append: 21
INSERTED 21 SUCESSFULLY

MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 1
Enter element to append: 45
INSERTED 45 SUCESSFULLY

MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 1
Enter element to append: 34
INSERTED 34 SUCESSFULLY

MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 1
Enter element to append: 98
INSERTED 98 SUCESSFULLY

MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 1
Enter element to append: 88
INSERTED 88 SUCESSFULLY

MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 1
Enter element to append: 10
INSERTED 10 SUCESSFULLY

MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 3

Hash Table:

10

21--->1

2



34

45





88--->98


MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 2
Enter element to find: 23

Element 23 was not found.
MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 2
Enter element to find: 98

Element 98 was found at Index 2 in Bucket 8.
MENU
1.Insert
2.Find
3.Display
4.Exit
Enter choice: 4
Exitting...
*/
