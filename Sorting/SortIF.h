typedef struct{
		int size;
		int *a;
		int cur_size;
}NumberADT;

void initADT(NumberADT *N, int size); 						//– To initialize the size of the array                                                               
void insertElements (NumberADT *N, int *x);	//– To copy the elements from x to the array in numberADT
void selectionSort(NumberADT *N);						//– Sorting of elements in the array using selection sort                                                                             
void shellSort(NumberADT *N);					//– Sorting of elements in the array using shell sort                                                                                                                                            
void display(NumberADT *N);						//– Display the elements in the array