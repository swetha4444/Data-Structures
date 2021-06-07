#include"digkstraimpl.h"
void main()
{
	char s[100],d[100];
	cityADT *c;
	int ch;
	do
	{
		printf("choose:\n1.create\n2.display\n3.Digkstra output\n4.check connectivity\n5.reset\n6.exit\nyour choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :c=create(c);
					break;
			case 2 :disp(c);
					break;
			case 3 :printf("Enter Starting Node : ");
					scanf("%s",s);
					DigkstraAlgo(c,s);break;
			case 4 :printf("enter source and destination cities\n");
					scanf("%s",s);
					scanf("%s",d);
					shortestPath(c,s,d);
					break;
			case 5 :reset(c);
					break;
			case 6 :break;
			default:printf("Invalid");
		}
	}while(ch!=6);
}


