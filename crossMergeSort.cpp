
void swap(int* p, int* q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

//merge function
void merge(int *arr, int* sub1, int* sub2,int size, long &comparison){
    int i = 0;
    int i1 = 0;
    int i2 = 0;
    for(i=0;i<size;i++){
        comparison++;
        if(sub1[i1] <= sub2[i2]){
            arr[i] = sub1[i1];
			i1++;
            if(i1==size/2){
				for(int j=i+1; j<size;j++,i2++){
					arr[j] = sub2[i2];
				}
				return;
			}
        }
        else{
            arr[i] = sub2[i2];
            i2++;
			if(i2==size/2){
				for(int j=i+1; j<size;j++,i1++){
					arr[j] = sub1[i1]; 
				}
				return;
			}
        }
    }
}

int crossMergeSort(int *arr, long &comparison, int size)
{
    
	int num_of_calls=1;
	
	if(size<=1)
	    return num_of_calls;
    else if(size ==2){
        comparison++;
	    if(arr[0] > arr[1]) 
	        swap(arr,arr+1);
	    return num_of_calls;
    }
    int* q1 = arr + (size/4 - 1);
	int* q2 = arr + (size/2 - 1);
    int* q3 = arr + (3*size/4 - 1);
    int h1[size/2];
    int h2[size/2];
    
    //recursion calls
    num_of_calls += crossMergeSort(arr, comparison, size/4);
    num_of_calls += crossMergeSort(q1+1,comparison,size/4);
    num_of_calls += crossMergeSort(q2+1,comparison,size/4);
    num_of_calls += crossMergeSort(q3+1,comparison,size/4);
    
    //merging
    merge(h1,arr,q2+1,size/2,comparison);
    merge(h2,q1+1,q3+1,size/2,comparison);
    merge(arr,h1,h2,size,comparison);
    
	return num_of_calls;
	
}