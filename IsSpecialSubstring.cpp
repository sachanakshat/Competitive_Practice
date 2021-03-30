#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

bool isSpecialString(string s)
{
    int n = s.size();
    for(int i=0; i<n/2; i++)
    {
        if(s[i] != s[n-i-1])
            return false;
    }
    return true;
}

long findSub(string s)
{
    int n = s.size();
    if(n<=2)
        return n;
    
}

int main()
{
    auto start = high_resolution_clock::now();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}