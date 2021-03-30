#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void printArray(vector<int> &arr, int n)
{
    cout<<"\n---------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n---------------------------"<<endl;
}

int binarySearch(int arr[], int e, int pivot)
{
    int n = sizeof(arr);
    int low=0,high=pivot, mid;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == e)
            return mid;
        else if(arr[mid]>e)
            high = mid-1;
        else
        {
            low = mid+1;
        }
    }

    low = pivot+1,
    high = n-1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == e)
            return mid;
        else if(arr[mid]>e)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int findPivot(int arr[], int n)
{
    int s=0, e=n-1;
    int i = (s+e)/2;
    int prev = -1;
    while(arr[i-1]<=arr[i] && s<=e)
    {
        if(arr[i]>=arr[s] && ((prev!=-1 && arr[i]>=arr[prev]) || prev==-1) && arr[0]>arr[n-1])
            s = i+1;
        else
            e=i-1;
        prev = i;
        i=(s+e)/2;
    }
    return i;
}

int main()
{
    int n;
    cout<<"\nEnter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the array: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int pivot = findPivot(arr,n);
    cout<<"\nFind the element to search: ";
    int e;
    cin>>e;
    int foundindex = binarySearch(arr, e, pivot);
    if(foundindex!=-1)
        cout<<"\nFound at: "<<foundindex;
    else
        {
            cout<<"\nNot found!"<<endl;
        }

    return 0;
}