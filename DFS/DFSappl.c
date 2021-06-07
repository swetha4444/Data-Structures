#include"DFSif.h"
#include"DFSimpl.h"
void main()
{
	char s[100],d[100];
	cityADT *c;
	int ch;
	do
	{
		printf("Choose:\n1.create\n2.display\n3.DFS output\n4.check connectivity\n5.exit\nyour choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :c=create(c);
					break;
			case 2 :display(c);
					break;
			case 3 :DFS(c);break;
			case 4 :printf("Enter source and destination cities\n");
					scanf("%s",s);
					scanf("%s",d);
					checkConnectivity(c,s,d);
					break;
			case 5 :break;
			default:printf("Invalid");
		}
	}while(ch!=5);
}
/*
OUTPUT:
cs1183@jtl-20:~/Desktop$ gcc  DFSappl.c -o s
cs1183@jtl-20:~/Desktop$ ./s
Choose:
1.create
2.display
3.DFS output
4.check connectivity
5.exit
your choice:1

Enter the number of cities:3

Enter the city names:
a
b
c

From:a
To:b
Connection successfully added
Do you want to continue the connections? (y/n) y

From:b
To:c
Connection successfully added
Do you want to continue the connections? (y/n) y

From:c
To:a
Connection successfully added
Do you want to continue the connections? (y/n) n
Choose:
1.create
2.display
3.DFS output
4.check connectivity
5.exit
your choice:2
0  1  0  
0  0  1  
1  0  0  

Connections:
From a to b.

From b to c.

From c to a.

Choose:
1.create
2.display
3.DFS output
4.check connectivity
5.exit
your choice:3



Choose:
1.create
2.display
3.DFS output
4.check connectivity
5.exit
your choice:4
Enter source and destination cities
b
a
source found 
b
c
a
Choose:
1.create
2.display
3.DFS output
4.check connectivity
5.exit
your choice:5
*/
