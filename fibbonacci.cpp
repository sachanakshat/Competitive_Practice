#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int fibonacci(int n, unsigned long int *dyn) {

    if(n==0 || n==1)
    {
        dyn[n] = n;
        return dyn[n];
    }

    else
    {
        if(dyn[n-1] == -1)
            dyn[n-1] = fibonacci(n-1, dyn);
        if(dyn[n-2] == -1)
            dyn[n-2] == fibonacci(n-2, dyn);
        dyn[n] = dyn[n-1] + dyn[n-2];
        return dyn[n];
    }


    // Complete the function.

}

int main() {
    auto start = high_resolution_clock::now();

    int n = 100;
    // cin >> n;
    unsigned long int dyn[n];
    for(int i = 0; i<n; i++)
        dyn[i] = -1;
    cout << fibonacci(n, dyn);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}