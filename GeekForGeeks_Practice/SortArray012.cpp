#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

void print(vector<int> & v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    auto start = high_resolution_clock::now();

    int arr[] = {0,2,1,2,0};
    int i, j=0;
    int a = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(i = 0; i<2; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i == arr[j])
            {
                swap(arr[j], arr[a++]);
            }
        }
    }
    print(arr, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}