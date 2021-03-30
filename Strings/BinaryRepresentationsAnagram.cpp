// https://www.geeksforgeeks.org/check-binary-representations-two-numbers-anagram/
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<chrono>


using namespace std;
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();

    int a = 8;
    int b = 4;

    int a1 = 1, a0 = 0, b1 = 1, b0 = 0;

    while(a>1)
    {
        if(a%2 == 0)
            a0++;
        else
            a1++;
        
        a/=2;
    }

    while(b>1)
    {
        if(b%2 == 0)
            b0++;
        else
            b1++;
        
        b/=2;
    }

    cout<<"\na0 = "<<a0<<" a1 = "<<a1<<endl;
    cout<<"b0 = "<<b0<<" b1 = "<<b1<<endl; 

    if(a1==b1 && a0==b0)
        cout<<"\nYES"<<endl;
    else
    {
        cout<<"\nNO"<<endl;
    }
    

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}