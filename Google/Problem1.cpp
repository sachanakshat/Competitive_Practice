#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void print(vector<int> vect)
{
    cout<<"\n-------------------------------"<<endl;
    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<"\n-------------------------------"<<endl;
}

void print(int * arr, int n)
{
    cout<<"\n-------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n-------------------------------"<<endl;   
}

int main()
{
    auto start = high_resolution_clock::now();

    cout<<"\nMaximum value of subarrays = "<<maxsum<<endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}