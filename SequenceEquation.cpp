#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

// Complete the squares function below.
int squares(int a, int b) {
    int n1 = ceil(sqrt(a));
    int n2 = floor(sqrt(b));
    return n2-n1+1;
}

int main()
{
    auto start = high_resolution_clock::now();

    int t,a,b,sol;

    cin>>t;
    for(int i = 0; i<t; i++)
    {
        cin>>a>>b;
        sol = squares(a,b);
        cout<<"\n"<<sol;
    }
    cout<<"\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}