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
    int pivot=0;
    for(int i=0; i<n; i++)
    {
        arr[i] = gas[i]-cost[i];
    }

    print(arr,n);

    while(arr[pivot]<0 && pivot<n)
    {
        pivot++;
    }

    cout<<"Pivot = "<<pivot<<endl;
    // cout<<"cost[pivot] gas[pivot]"<<cost[pivot]<<" "<<gas[pivot]<<endl;

    if(pivot>n || cost[pivot]>gas[pivot])
        return -1;
    int fuel;
    for(int i=(pivot+1)%n; i<n; i++)
    {

        int j = i;
        fuel = arr[i-1];
        while(fuel>0 && j!=pivot)
        {
            cout<<"j = "<<j<<endl;
            fuel = fuel + arr[j];
            j = (j+1)%n;
        }
        cout<<"\n"<<endl;
        if(j==pivot)
            return pivot;
    }
    cout<<"Arrived last!"<<endl;
    return -1;

}

/*
vector<int> gas{1,2,3,4,5};
vector<int> cost{3,4,5,1,2};
*/

/*
vector<int> gas{5,1,2,3,4};
vector<int> cost{4,4,1,5,1};
*/

int main()
{
    auto start = high_resolution_clock::now();

    // vector<int> gas{1,2,3,4,5};
    // vector<int> cost{3,4,5,1,2};

    vector<int> gas{5,1,2,3,4};
    vector<int> cost{4,4,1,5,1};

    // vector<int> gas{3,3,4};
    // vector<int> cost{3,4,4};



    int sol = canCompleteCircuit(gas, cost);


    cout<<"\nIndex = "<<sol<<endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}