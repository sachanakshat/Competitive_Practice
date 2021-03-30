#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int main()
{
    // auto start = high_resolution_clock::now();
    int number,n3=0, num=0;
    cin>>number;
    vector<int> n2;
    while(number!=1)
    {
        // cout<<"\npushing back "<<number%2<<endl;
        n2.push_back(number%2);
        number/=2;
    }
    n2.push_back(1);

    while(n2.empty() == false)
    {
        n3 = n3 + n2[n2.size()-1]*pow(2,num++);
        n2.pop_back();
    }
    cout<<n3;

    // for(int i=n2.size()-1; i>=0; i--)
    // {
    //     cout<<n2[i];
    //     n2.pop_back();
    // }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}