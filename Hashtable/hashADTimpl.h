void init(hashADT *h, int size){
	int i;
	h->size=size;
	for(i=0;i<h->size;i++){
		h->list[i]=(hashADT*) malloc(sizeof(hashADT));
		h->list[i]->next=NULL;
	}
}

int hash(hashADT *h, int x){
	return x%(h->size);
}

void insert(hashADT *h, int x){
	int key;
	node *temp=NULL;
	key=hash(h,x);

	temp=(node*) malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;

    temp->next=h->list[key]->next;
    h->list[key]->next=temp;

	printf("INSERTED %d SUCESSFULLY\n",temp->data);
}

void searchElement( hashADT *h, int x){
	int key=hash(h,x);
	int flag=-1,pos=-1;
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp=h->list[key];

	while(temp!=NULL){
        pos++;
		if(temp->data==x){
			printf("\nElement %d was found at Index %d in Bucket %d.",x,pos,key);
			flag++;
		}
		temp=temp->next; //incase all occurences needs to be diaplayed
	}
	if(flag==-1)
		printf("\nElement %d was not found.",x);
}

void display(hashADT *h){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	int key=0;
	printf("\nHash Table: ");
	while(key<h->size){			//Traversing each bucket one by one
		temp=h->list[key]->next;
		printf("\n\n");
		while(temp!=NULL){
			printf("%d",temp->data);
			temp=temp->next;
			if(temp!=NULL)
				printf("--->");
		}
		key++;
	}
}


