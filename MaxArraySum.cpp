#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int mas(vector<int>& arr, int n)
{
    int sum1;
    cout<<"\nn = "<<n<<endl;
    if(n<=1)
    {
        if(n<0)
            return 0;
        return arr[n];
    }
    else
    {
        sum1=arr[n] + max(mas(arr, n-2), mas(arr, n-3));
        return max(arr[n], sum1);
    }
}

int main()
{
    auto start = high_resolution_clock::now();

    // vector<int> arr{2,1,5,8,4};
    vector<int> arr{3,5,-7,8,10};
    // vector<int> arr{3,7,4,6,5};
    int n = arr.size();

    int *tab;
    tab = (int*)malloc(n * sizeof(int));

    int maxsum1 = mas(arr, n-1);
    int maxsum2 = mas(arr, n-2);

    int maxsum = max(maxsum1, maxsum2);

    cout<<"\nMaximum value of subarrays = "<<maxsum<<endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}