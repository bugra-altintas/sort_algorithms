void swap(int* p, int* q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

int sillySort(int* arr, long &comparison, long & swaps, int size) 
{
    int num_of_calls=1;
	
	if(size >= 2 && size < 4){
	    comparison++;
	    if(arr[0] > arr[1]) {
	        swaps++;
	        swap(arr,arr+1);
	    }
	}
	else if(size >= 4){
	    int* q1 = arr + (size/4 - 1);
	    int* q2 = arr + (size/2 - 1);
	    int* q3 = arr + (3*size/4 - 1);
	    //recursion calls
	    return num_of_calls + sillySort(arr, comparison, swaps, size/2) + 
				sillySort(q1+1, comparison, swaps, size/2) + sillySort(q2+1, comparison, swaps, size/2) + 
				sillySort(arr, comparison, swaps, size/2) + sillySort(q1+1, comparison, swaps, size/2) + 
				sillySort(arr, comparison, swaps, size/2);
	}
	
	return num_of_calls;
}