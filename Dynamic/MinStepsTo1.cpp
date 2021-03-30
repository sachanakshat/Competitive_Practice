#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

#define MAX = INT32_MAX;

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

int countsteps(int n, vector<int> &tab)
{
    // cout<<"Function called"<<endl;

    if(n == 1)
        return tab[n] = 0;
    else if(tab[n]!=INT32_MAX)
        return tab[n];
    else
    {
        int n1 = INT32_MAX;
        int n2 = INT32_MAX;
        int n3 = INT32_MAX;

        if(n%3 == 0)
            n3 = 1+countsteps(n/3, tab);
        if(n%2 == 0)
            n2 = 1+countsteps(n/2, tab);
        
        n1 = 1+countsteps(n-1, tab);

        if(n3<tab[n/3])
            tab[n/3] = n3;
        if(n2<tab[n/2])
            tab[n/2] = n2;
        if(n1<tab[n-1])
            tab[n-1] = n1;

        cout<<"\ntab["<<n/3<<"] = "<<tab[n/3]<<" tab["<<n/2<<"] = "<<tab[n/2]<<" tab["<<n-1<<"] = "<<tab[n-1]<<endl;

        cout<<"\nn3 = "<<n3<<"\nn2 = "<<n2<<"\nn1 = "<<n1<<endl;
        cout<<"\nMin = "<<min(n3,n2,n1)<<endl;

        int minimum = min(n3,n2,n1);
        tab[n] = minimum;
        return tab[n];
    }
    
}

int main()
{
    auto start = high_resolution_clock::now();

    int n = 10;
    vector<int> tab(n+1, INT32_MAX);
    
    int sol = countsteps(n, tab);
    cout<<"\nSolution = "<<sol<<endl;

    for(int i = 0; i<n; i++)
    {
        cout<<"\ntab["<<i<<"] = "<<tab[i]<<endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}