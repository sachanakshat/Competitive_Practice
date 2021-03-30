#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int swaps = 0;

void swap(int *i, int *j)
{
    // cout<<"Before swap "<<*i<<" "<<*j<<"\n";
    int k = *i;
    *i = *j;
    *j = k;
    // cout<<"After swap "<<*i<<" "<<*j<<"\n";
}

int * bubble(int arr[], int n)
{
    int i,j;
    for(i = 0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
                swap(&arr[i], &arr[j]);
        }
    }
    return arr;
}

void printvector(vector<int> array)
{
    int n = array.size();
    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

void shwap(vector<int> &a, int i, int j)
{
    // cout<<"Before swap "<<*i<<" "<<*j<<"\n";
    int k = a[i];
    a[i] = a[j];
    a[j] = k;
    swaps++;
    cout<<"\nAfter Swapping:";
    printvector(a);
    // cout<<"After swap "<<*i<<" "<<*j<<"\n";
}

void countSwaps(vector<int>& a) {
    int i,j, n = a.size();
    for(i = 0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            printvector(a);
            cout<<"\ni = "<<i<<" j = "<<j;
            cout<<"\na["<<j<<"] and a["<<j+1<<"] = "<<a[j]<<" "<<a[j+1]<<endl;
            if(a[j]>a[j+1])
                shwap(a, j, j+1);
        }
        cout<<"\n";
    }
}

int main()
{
    // int arr[] = {2,46,86,18,62,8,9,5,89,5,68,94};

    vector<int> a{3,2,1};
    int n = a.size();
    // int n = sizeof(arr)/sizeof(arr[0]);
    // bubble(arr, n);
    countSwaps(a);
    cout<<"Array is sorted in "<<swaps<<" swaps."<<endl;
    cout<<"First Element: "<<a[0]<<endl;
    cout<<"Last Element: "<<a[n-1]<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}