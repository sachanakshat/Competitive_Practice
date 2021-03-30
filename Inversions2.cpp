#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void show(int a[], int n)
{
    // cout<<"\nArray:\n";
    // int n = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void show(vector<int> arr, int startindex, int endindex)
{
    for(int i = startindex; i<=endindex; i++)
    {
        cout<<arr[i];
    }
}

long merge(vector<int>& arr,int temp[], int start, int mid, int end)
{
    int inversions = 0;
    int i, j, k;
    i=start;
    j=mid+1;
    k=start;
    cout<<"\nMerging ";
    show(arr, start, mid);
    cout<<" and ";
    show(arr, mid+1, end);
    cout<<endl;
    while(i<=mid && j<=end)
    {
        cout<<"i = "<<i<<" mid = "<<mid<<" j = "<<j<<" end = "<<end<<endl;
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cout<<"\tInverted! Incremented by "<<mid-i+1<<endl;
            inversions+=(mid-i+1);
            cout<<"Inversions = "<<inversions<<endl;
        }
    }

    while(i<=mid)
        temp[k++]  =arr[i++];
    while(j<=end)
        temp[k++] = arr[j++];
    
    cout<<"\ntemp array:"<<endl;
    show(temp, arr.size());
    for(i=start; i<=end; i++)
    {
        // cout<<"\narr["<<i<<"] = "<<arr[i]<<" temp["<<i<<"] = "<<temp[i]<<endl;
        arr[i] = temp[i];
    }
    
    cout<<"\nMerged array:"<<endl;
    show(arr, start, end);
    cout<<"\nReturning(merge procedure): "<<inversions<<endl;

    return inversions;
}

long mergesort(vector<int>& arr, int temp[], int start, int end)
{
    long inversions=0;
    if(start<end)
    {
        cout<<"\nMerge sort on ("<<start<<","<<(start+end)/2<<") and ("<<(start+end)/2+1<<","<<end<<")"<<endl;
        inversions += mergesort(arr, temp, start, (start+end)/2);
        inversions += mergesort(arr, temp, (start+end)/2+1, end);
        cout<<"\nMerging ("<<start<<","<<(start+end)/2<<") and ("<<(start+end)/2+1<<","<<end<<")"<<endl;
        inversions += merge(arr, temp, start, (start+end)/2, end);
    }

    cout<<"\nReturning(mergesort): "<<inversions<<endl;
    return inversions;
}

long countInversions(vector<int> arr) {

    int n = arr.size();
    int temp[n];
    return mergesort(arr, temp, 0, n-1);

}

int main()
{
    auto start = high_resolution_clock::now();
    // int a[10] = {15,45,32,41,65,12,95,23,25,65};
    // vector<int> arr{1,1,1,2,2};
    vector<int> arr{2,1,5,3,4};
    // vector<int> arr{2,4,1,5,3};
    int inversions = countInversions(arr);
    cout<<"\nNumber of inverisons = "<<inversions<<"\n";


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}