#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int floorXi(int arr[], int n, int e)
{
    if(e>arr[n-1])
        return arr[n-1];
    int low=0,high=n-1, mid;

    while(low<=high)
    {
        mid = (low+high)/2;
        // cout<<"low = "<<low<<" mid = "<<mid<<" high = "<<high<<endl;
        if((mid==n-1) || (arr[mid]<=e && arr[mid+1]>e))
            return mid;
        else if( arr[mid]<e)
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
    int n,s;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int sol = floorXi(arr, n, 15);
    cout<<sol<<endl;
    return 0;
}