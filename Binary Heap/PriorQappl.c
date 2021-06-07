#include<stdio.h>
#include"PriorQintfc.h"
#include"PriorQimpl.h"

void main()
{
	PQ *p;
	int s,ch;
	printf("Enter the size of Heap:");
	scanf("%d",&s);
	p=PQinit(s);
	do
	{
		printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\nChoice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :p = PQinsert(p,getempl());
				break;
			case 2 :p = PQdelete(p);
				break;
			case 3 :PQdisplay(p,1,0);
				break;
			case 4 :break;
			default:printf("Invalid \n");
		}
	}while(ch!=4);

}

/*
OUTPUT:
Enter the size of Heap:5


1.Insert
2.Delete
3.Display
4.Exit
Choice: 1
Name   : 2
Id     : 2
Salary : 2


1.Insert
2.Delete
3.Display
4.Exit
Choice: 1
Name   : 1
Id     : 1
Salary : 1


1.Insert
2.Delete
3.Display
4.Exit
Choice: 1
Name   : 0
Id     : 0
Salary : 0


1.Insert
2.Delete
3.Display
4.Exit
Choice: 1
Name   : 4
Id     : 4
Salary : 4


1.Insert
2.Delete
3.Display
4.Exit
Choice: 3
_____________
Name   : 0
Id     : 0
Salary : 0.00
_____________


        _____________
        Name   : 2
        Id     : 2
        Salary : 2.00
        _____________


                _____________
                Name   : 4
                Id     : 4
                Salary : 4.00
                _____________


        _____________
        Name   : 1
        Id     : 1
        Salary : 1.00
        _____________




1.Insert
2.Delete
3.Display
4.Exit
Choice: 2
_____________
Name   : 0
Id     : 0
Salary : 0.00
_____________



1.Insert
2.Delete
3.Display
4.Exit
Choice: 3
_____________
Name   : 1
Id     : 1
Salary : 1.00
_____________


        _____________
        Name   : 2
        Id     : 2
        Salary : 2.00
        _____________


        _____________
        Name   : 4
        Id     : 4
        Salary : 4.00
        _____________




1.Insert
2.Delete
3.Display
4.Exit
Choice: 2
_____________
Name   : 1
Id     : 1
Salary : 1.00
_____________



1.Insert
2.Delete
3.Display
4.Exit
Choice: 3
_____________
Name   : 2
Id     : 2
Salary : 2.00
_____________


        _____________
        Name   : 4
        Id     : 4
        Salary : 4.00
        _____________




1.Insert
2.Delete
3.Display
4.Exit
Choice: 4
*/
