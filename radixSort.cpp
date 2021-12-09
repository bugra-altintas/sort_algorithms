#include <iostream>
#include <cmath>
/*
    arr       : array to be sorted, in order to get points this array should contain be in sorted state before returning
    ascending : true for ascending, false for descending 
    n         : number of elements in the array
    l         : the number of characters used in counting sort at each time
    
*/

int twosix(std::string str,int pos, int l){
    int sum = 0;
    for(int i = 0; i<l;i++){
        sum+=pow(26,l-i-1)*(str.substr(pos,l)[i]-65);
    }
    return sum;
}

void countingSort(int& iterations, std::string A[], int size, int l, int pos, bool ascending){
    int k = pow(26,l);
    int* C = new int[k];
    std::string B[size];
    for(int j = 0; j<size;j++){//LOOP 1
        C[twosix(A[j],pos,l)]++;
        iterations++;
    }
    for(int i = 1;i<k;i++){//LOOP 2
        C[i] += C[i-1];
        iterations++;
    }
    if(ascending){
        for(int j = size-1; j>=0;j--){//LOOP 3-ascending
            B[C[twosix(A[j],pos,l)] - 1] = A[j];
            C[twosix(A[j],pos,l)]--;
            iterations++;
        }
    }
    else{
        for(int j = 0; j<size;j++){//LOOP 3-descending
            B[size - C[twosix(A[j],pos,l)]] = A[j];
            C[twosix(A[j],pos,l)]--;
            iterations++;
        }
    }
    for(int i=0; i<size; i++){//LOOP 4-copying back
        A[i] = B[i];
        iterations++;
    }
}
int radixSort(std::string arr[], bool ascending, int n, int l){
    int iterations = 0;
    int length = arr[0].size();
	int pos = length-l;
	int count = length%l ? length/l + 1 : length/l;
	for(int i = 0; i<count;i++,pos-=l){
		if(pos<0){// in case of  length%l != 0
			l += pos;
			pos = 0;
		}
		countingSort(iterations,arr,n,l,pos,ascending);
		iterations++;
	}
	
    return iterations;    
    
}
