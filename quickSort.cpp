void swap(unsigned short* p, unsigned short* q){
    if(p != q){
        int temp = *p;
        *p = *q;
        *q = temp;
    }
}
//returns the pivot index
int classical_partition(unsigned short* arr, long &swaps, double & avg_dist, double & max_dist, int size){
    int pivot = size-1;
    int i = -1;
    double sum_dist = avg_dist*swaps;
    double local_sum_dist = 0;
    for(int j=0;j<pivot;j++){
        if(arr[j]>=arr[pivot]){
            i++;
            swap(arr+j,arr+i);
            swaps++;
            local_sum_dist += j-i;
            max_dist = j-i > max_dist ? j-i : max_dist;
        }
    }
    swap(arr+i+1,arr+pivot);
    swaps++;
    local_sum_dist += pivot-(i+1);
    max_dist = pivot-(i+1) > max_dist ? pivot-(i+1) : max_dist;
    avg_dist = swaps ? (local_sum_dist + sum_dist)/swaps : 0;
    return i+1;
} 

//returns the pivot index
int hoare_partition(unsigned short* arr, long &swaps, double & avg_dist, double & max_dist, int size){
    int pivot = arr[(size-1)/2];
    int i = -1;
    int j = size;
    double sum_dist = avg_dist*swaps;
    double local_sum_dist = 0;
    while(true){
        do{
            j--;
        }
        while(arr[j]<pivot);
        do{
            i++;
        }
        while (arr[i]>pivot);
        if(i<j){
            swap(arr+i,arr+j);
            swaps++;
            local_sum_dist += j-i;
            if(j-i > max_dist){
                max_dist = j-i;
            }
        }
        else{
            avg_dist = swaps ? (local_sum_dist + sum_dist)/swaps : 0;
            return j;
        }
    }
    return 0;
} 

void quickSort(unsigned short* arr, long &swaps, double & avg_dist, double & max_dist, bool hoare, int size)
{
    if(hoare){
        if(size > 1){
            int pivot = hoare_partition(arr, swaps, avg_dist, max_dist, size);
            quickSort(arr, swaps, avg_dist, max_dist, hoare, pivot+1);
            quickSort(arr+pivot+1, swaps, avg_dist, max_dist, hoare, size-(pivot+1));
        }
    }
    else{
        if(size>1){
            int pivot = classical_partition(arr, swaps, avg_dist, max_dist, size);
            quickSort(arr, swaps, avg_dist, max_dist, hoare, pivot);
            quickSort(arr+pivot+1, swaps, avg_dist, max_dist, hoare, size-pivot-1);
        }
    }
	
}