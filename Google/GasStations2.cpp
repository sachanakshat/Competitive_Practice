// https://www.interviewbit.com/problems/gas-station/
// https://leetcode.com/problems/gas-station/
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void print(vector<int> vect)
{
    cout<<"\n-------------------------------"<<endl;
    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<"\n-------------------------------"<<endl;
}

void print(int * arr, int n)
{
    cout<<"\n-------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n-------------------------------"<<endl;   
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int n = gas.size();
    int * arr = (int*)malloc(sizeof(int)*n);
    int pivot=0, netcost;
    for(int i=0; i<n; i++)
    {
        arr[i] = gas[i]-cost[i];
    }
    // arr[n-1] = gas[0]-cost[n-1];

    print(arr,n);

    for(int i=0; i<n; i++)
    {
        pivot = i;
        netcost = arr[pivot];
        cout<<"\nOutside:\nPivot = "<<pivot<<"\nNet cost = "<<netcost<<endl;
        while(pivot!=((i+n-1)%n) && netcost>0)
        {
            cout<<"\nInside:\nPivot = "<<pivot<<"\nNet cost = "<<netcost<<endl;
            pivot = (pivot + 1)%n;
            netcost = netcost + arr[pivot];
        }
        if(pivot==((i+n-1)%n))
            return i;
    }

    return -1;
}

int main()
{
    auto start = high_resolution_clock::now();

    // vector<int> gas{1,2,3,4,5};
    // vector<int> cost{3,4,5,1,2};
    //3

    // vector<int> gas{5,1,2,3,4};
    // vector<int> cost{4,4,1,5,1};
    //4

    // vector<int> gas{3,3,4};
    // vector<int> cost{3,4,4};

    vector<int> gas{4,5,3,1,4};
    vector<int> cost{5,4,3,4,2};
    //-1




    int sol = canCompleteCircuit(gas, cost);


    cout<<"\nIndex = "<<sol<<endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}