#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b=temp;
}

void printvector(vector<int>& arr)
{
    cout<<"\n-------------------------"<<endl;
    for(int i=0; i<arr.size(); i++)
    {

        cout<<arr[i]<<" ";
    }
    cout<<"\n-------------------------"<<endl;
}

int minimumSwaps(vector<int> arr) {
    
    int n = arr.size();
    int swaps=0;
    for(int i=1; i<=n; i++)
    {
        printvector(arr);
        if(arr[i-1]!=i)
        {
            cout<<"Swapping "<<arr[i-1]<<" and "<<arr[arr[i-1]]<<endl;
            swap(arr[i-1], arr[arr[i-1]-1]);
            swaps++;
            i--;
        }
        printvector(arr);
    }
    return swaps;

}

int main()
{
    auto start = high_resolution_clock::now();

    vector<int> arr{4,3,1,2};
    int sol = minimumSwaps(arr);
    cout<<"\nMinimum Swaps = "<<sol<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}