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

    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };

    int n = 9, m=0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
        {
            swap(arr[i], arr[m++]);
        }
    }

    print(arr, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}