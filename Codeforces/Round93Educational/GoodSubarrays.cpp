#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

static int count = 0;

void subarraysum(vector<int> v,int m,int n,vector<int>::iterator ptr)
{
    if(ptr==)
    {
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum == v.size())
            count++;
        return;
    }

    subarraysum(v, m,n, ptr--);
    v.erase(v)
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