/*

Written by @sachanakshat


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int *i, int *j)
{
    cout<<"Before swap "<<*i<<" "<<*j<<"\n";
    int k = *i;
    *i=*j;
    *j=k;
    cout<<"After swap "<<*i<<" "<<*j<<"\n";
}

int partition(int a[], int p, int r)
{
    int pivot = a[r];
    int i = p-1;
    for(int j = p; j<=r-1; j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return (i+1);
}

void quicksort(int a[], int p, int r)
{
    if(p<r)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

int main()
{
    int a[] = {2,46,86,18,62,8,9,5,89,5,68,94};
    int n = sizeof(a)/sizeof(a[0]);
    quicksort(a, 0, n-1);
    cout<<"Sorted Array = ";
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}









// /* C++ implementation of QuickSort */
// #include <bits/stdc++.h> 
// using namespace std; 

// // A utility function to swap two elements 
// void swap(int* a, int* b) 
// { 
// 	int t = *a; 
// 	*a = *b; 
// 	*b = t; 
// } 

// /* This function takes last element as pivot, places 
// the pivot element at its correct position in sorted 
// array, and places all smaller (smaller than pivot) 
// to left of pivot and all greater elements to right 
// of pivot */
// int partition (int arr[], int low, int high) 
// { 
// 	int pivot = arr[high]; // pivot 
// 	int i = (low - 1); // Index of smaller element 

// 	for (int j = low; j <= high - 1; j++) 
// 	{ 
// 		// If current element is smaller than the pivot 
// 		if (arr[j] < pivot) 
// 		{ 
// 			i++; // increment index of smaller element 
// 			swap(&arr[i], &arr[j]); 
// 		} 
// 	} 
// 	swap(&arr[i + 1], &arr[high]); 
// 	return (i + 1); 
// } 

// /* The main function that implements QuickSort 
// arr[] --> Array to be sorted, 
// low --> Starting index, 
// high --> Ending index */
// void quickSort(int arr[], int low, int high) 
// { 
// 	if (low < high) 
// 	{ 
// 		/* pi is partitioning index, arr[p] is now 
// 		at right place */
// 		int pi = partition(arr, low, high); 

// 		// Separately sort elements before 
// 		// partition and after partition 
// 		quickSort(arr, low, pi - 1); 
// 		quickSort(arr, pi + 1, high); 
// 	} 
// } 

// /* Function to print an array */
// void printArray(int arr[], int size) 
// { 
// 	int i; 
// 	for (i = 0; i < size; i++) 
// 		cout << arr[i] << " "; 
// 	cout << endl; 
// } 

// // Driver Code 
// int main() 
// { 
// 	int arr[] = {10, 7, 8, 9, 1, 5}; 
// 	int n = sizeof(arr) / sizeof(arr[0]); 
// 	quickSort(arr, 0, n - 1); 
// 	cout << "Sorted array: \n"; 
// 	printArray(arr, n); 
// 	return 0; 
// } 

// // This code is contributed by rathbhupendra 