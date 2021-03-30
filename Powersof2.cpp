#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

long son2(long long int *a, long long int n)
{
    long long int sum = 0;

    for(int i = 0; i<n; i++)
    {
        int x = a[i];

        while(x!=1)
        {
            if(x%2!=0)
            {
                break;
            }
            x=x/2;
        }
        if(x==1)
            sum+=a[i];
    }

    return sum;
}

int main()
{
    auto start = high_resolution_clock::now();

    int n;
    cin>>n;
    long long int *a = (long long int *)malloc(sizeof(long long int*)*n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    cout<<son2(a, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}