typedef struct{
	int data;
	struct node *next;
}node;

typedef struct{
	int size;
	node* list[100];
}hashADT;

void init(hashADT *h, int size);
void insert(hashADT *h, int x);
void searchElement(hashADT *h, int x);
void display(hashADT *h);
