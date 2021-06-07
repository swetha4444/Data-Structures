#include <stdio.h>
#include <stdlib.h>
#include "cityADTIf.h"
#include "cityADTImpl.h"

void main()
{

	int op;
    char ini[20],fin[20];

	cityADT *c;
	c=(cityADT*)malloc(sizeof(cityADT));



    do{
		printf("\nMenu\n");
		printf("[1]Create\n");
		printf("[2]Display\n");
		printf("[3]BFS\n");
		printf("[4]Check Connectivity\n");
		printf("[0]EXIT");

		printf("\nEnter choice:");
		scanf("%d",&op);

		switch(op)
		{

			case 1:
				create(c);
				break;

			case 2:
				display(c);
				break;

            case 3:
                BFS(c);
                break;

            case 4:
                printf("Enter initial place: ");
                scanf("%s",ini);
                printf("Enter final destination: ");
                scanf("%s",fin);
                if(checkConnectivity(c,ini,fin)==1)
					printf("They are connected\n");
                else
					printf("They are not connected\n");
                break;
            case 0:
                exit(1);

            default:
                printf("INVALID <TRY AGAIN>");

		}
	}while(op!=0);
}
