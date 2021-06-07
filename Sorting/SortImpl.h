void initADT(NumberADT *N, int size){
	N->size=size;
	N->a=(int *)malloc(sizeof(int)*size);
	N->cur_size=0;
}

void insertElements(NumberADT *N, int *a){
	int i=0;
	N->cur_size=0;
	int len=N->size;
	while(a[i]){
		N->a[i]=a[i];
		i++;
		N->cur_size++;
	}
}

void selectionSort(NumberADT *N){ 
    int i, j, min,temp;
    int n=N->cur_size;

    for(i=0;i<n-1;i++){ 
    	min=i; 
        for(j=i+1;j<n;j++) 
        	if (N->a[j]<N->a[min]) 
        		min=j;
        temp=N->a[min];
        N->a[min]=N->a[i];
        N->a[i]=temp;
    } 
}

void shellSort(NumberADT *N){
	int gap,i,j,temp;
	int n=N->cur_size;
	for (gap=n/2;gap>0;gap/=2){  
    	for (i=gap;i<n;i+=1){ 
        	int temp = N->a[i];           
            for (j=i;j>=gap && N->a[j-gap]>temp;j-=gap) 
            	N->a[j] = N->a[j-gap]; 
            N->a[j] = temp; 
        } 
    } 
}

void display(NumberADT *N){
	int n=N->cur_size;
	int i=0;
	printf("\nElements of the Array:\n");
	while(i<n){
		printf("%d\t",N->a[i]);
		i++;
	}
}