# Sorts
-Silly Sort
This sorting algorithm divides the given array **arr** into quarters and sorts by making 6 recursive calls. The function **sillySort** returns the total number of calls. Also, it counts the number of **comparison**s and **swap**s executed.

- Cross Merge Sort
**Cross merge sort**  is a variation of k-way merge sort, where **k is 4** and the partitions are merged in a different order. First quarter is merged with third quarter and second quarter is merged with fourth quarter. Then, these merged arrays are merged. **crossMergeSort** returns the number of calls of **crossMergeSort()**. Also, the function traces the number of **comparison**s executed.

- Quick Sort
**quickSort** sorting algorithm has two different parititioning algorithms in this implementation, **Classical** partition and **Hoare** partition. **quickSort()** function sorts the array **arr** in descending order. It counts the number of **swap**s executed during sorting process, calculates the average distance between swap positions **avg_dist**, find the max distance between swap positions **max_dist**.

- 3-way Quick Sort
In 3-way QuickSort, an array arr[l..r] is divided into three parts in partition process. **quickSort3()** function sorts the array in descending order, counts the number of **swap**s executed during sorting process and counts the number of **comparison**s executed during sorting proccess. 

- Radix Sort
In this **Radix Sort** algorithm, **radixSort()** function sorts given array **std::string arr** in ascending or descending depending on the variable **ascending** by using *Counting Sort* algorithm as a subroutine. It treats to strings as a number in base 26 by using **str_to_26()** helper function. **radixSort()** function returns the number of **iterations** done in the loops of the *Counting Sort* algorithm.
