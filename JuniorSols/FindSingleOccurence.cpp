#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int binarySearch(int arr[], int n)
{
    int low=0,high=n-1, mid;

    while(low<=high)
    {
        mid = (low+high)/2;
        // cout<<"low = "<<low<<" mid = "<<mid<<" high = "<<high<<endl;
        if( (mid%2==0 && mid==n-1) || (mid%2==0 && arr[mid+1]!=arr[mid]))
            return mid;
        else if( mid%2==0 && arr[mid]==arr[mid+1])
            low = mid+1;
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<endl;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements of the array"<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"\nThe index is "<<binarySearch(arr, n)<<endl;
    
    return 0;
}