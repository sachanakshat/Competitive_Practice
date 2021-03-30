#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int n,i;
    cout<<"Enter the number of elements in an array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements: ";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int r1 = arr[1]/arr[0];
    int r2 = arr[2]/arr[1];
    int r3 = arr[3]/arr[2];
    int ratio;
    if(r1==r2)
        ratio = r1;
    else if(r2==r3)
        ratio = r2;
    else if(r1==r3)
        ratio = r1;
    for(i=1; i<n; i++)
    {
        if(arr[i]!=arr[i-1]*ratio)
        {
            cout<<arr[i-1]*ratio<<endl;
            break;
        }
    }
    return 0;
}