#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int min(int n1, int n2, int n3)
{
    if(n1<=n2 && n1<=n3)
        return n1;
    else if(n2<=n1 && n2<=n3)
        return n2;
    else
        return n3;
}

int countsteps(int n)
{
    // cout<<"Function called"<<endl;
    if(n == 1)
        return 0;

    int n1 = INT32_MAX;
    int n2 = INT32_MAX;
    int n3 = INT32_MAX;

    if(n%3 ==0)
        n3 = 1+countsteps(n/3);
    if(n%2 == 0)
        n2 = 1+countsteps(n/2);

    n1 = 1+countsteps(n-1);

    // cout<<"\nn1 = "<<n1<<"\nn2 = "<<n2<<"\nn3 = "<<n3<<endl;
    // cout<<"\nMin = "<<min(n1,n2,n3)<<endl;

    return min(n1,n2,n3);
    
}

int main()
{
    auto start = high_resolution_clock::now();

    int n = 6;
    int sol = countsteps(n);

    cout<<"\nSolution = "<<sol<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}