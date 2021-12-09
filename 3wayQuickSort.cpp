
void swap(unsigned short* p, unsigned short* q){
    if(p != q){
        int temp = *p;
        *p = *q;
        *q = temp;
    }
}

void three_way_partition(unsigned short *arr, long &swaps, long &comparison, int size, int* ends){
    int i=0;
    int j=0;
    int pivot = size-1;
    while(i<pivot){
        comparison++;
        if(arr[i]>arr[pivot]){
            swap(arr+i,arr+j);
            swaps++;
            i++;
            j++;
        }
        else if(arr[i]==arr[pivot]){
            pivot--;
            swap(arr+i,arr+pivot);
            swaps++;
            comparison++;
        }
        else{
            i++;
            comparison++;
        }
    }
    int m = pivot-j < size -pivot ? pivot-j : size-pivot;
    
    for(int k=0;k<m;k++){
        swap(arr+j+k,arr+size-m+k);
        swaps++;
    }
    ends[0] = j;
    ends[1] = pivot-j;
}

void quickSort3(unsigned short *arr, long &swaps, long &comparison, int size) {
	if(size>1){
	    int* ends = new int[2];
	    three_way_partition(arr,swaps,comparison,size,ends);
	    quickSort3(arr,swaps,comparison,ends[0]);
	    quickSort3(arr+(size-ends[1]),swaps,comparison,ends[1]);
	}
}