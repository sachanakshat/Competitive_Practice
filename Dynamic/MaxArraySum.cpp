#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int mas(vector<int>& arr, int n, int *tab)
{
    int sum1;
    if(n<=1)
    {
        if(n<0)
            return 0;
        tab[n] = arr[n];
        return tab[n];
    }
    else
    {
        if(tab[n] == INT32_MIN)
        {
            sum1=arr[n] + max(mas(arr, n-2, tab), mas(arr, n-3, tab));
            tab[n] = max(arr[n], sum1);
        }
        return tab[n];
    }
}

int main()
{
    auto start = high_resolution_clock::now();

    int n, val;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>val;
        arr.push_back(val);
    }
    // vector<int> arr{2,1,5,8,4};
    // vector<int> arr{3,7,4,6,5};
    // vector<int> arr{3,5,-7,8,10};
    // int n = arr.size();
    int *tab;
    tab = (int*)malloc(n * sizeof(int));

    //Initializing the table
    for(int i = 0; i<n; i++)
        tab[i] = INT32_MIN;

    int maxsum1 = mas(arr, n-1, tab);
    int maxsum2 = mas(arr, n-2, tab);

    int maxsum = max(maxsum1, maxsum2);

    cout<<"\nMaximum value of subarrays = "<<maxsum<<endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}