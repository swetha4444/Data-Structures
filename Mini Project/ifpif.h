typedef struct
{
	char name[20],dob[20],address[30],contact[11];
	char nationality[20],board[11];
	int admno,cut_off;
	char password[20],gender[10];
	int stat;
}studentDetails;

typedef struct
{
	studentDetails arr[5];
	int size,cap,marks;
}Samecut_list;

typedef struct CSE_BSTnode
{
	int mark;
	Samecut_list *l;
	struct CSE_BSTnode *lptr, *rptr;
}CSE_BSTnode;

Samecut_list *init();
CSE_BSTnode *initialize(CSE_BSTnode *P);
int isFull(Samecut_list* l);
Samecut_list *listinsert(Samecut_list *l,studentDetails a);
CSE_BSTnode *insert(CSE_BSTnode *P,studentDetails x);
void listdisplay(Samecut_list *l);
void dispTree(CSE_BSTnode *P, int space);

CSE_BSTnode *findMin(CSE_BSTnode *P);
Samecut_list *cancel(Samecut_list *l,int ano);
CSE_BSTnode *Delete(CSE_BSTnode *P,int cut);
CSE_BSTnode *Cancellation(CSE_BSTnode *P,int ano,int cut);

studentDetails findPassword(CSE_BSTnode *P,char name[],int m);

void Status(CSE_BSTnode *P);
CSE_BSTnode *admission(CSE_BSTnode *P);
void showAdmission(CSE_BSTnode *P,int ano,int m);

