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

void fillabove(int s1, int s2, int n, int m, vector<int>& arr)
{
    if()
    return;
}

int main()
{
    auto start = high_resolution_clock::now();

    int n,m,s1,s2,var;
    for(int i=0; i<4; i++)
    {
        cin>>n;
        cin>>m;
        cin>>s1;
        cin>>s2;
    }
    vector<vector<int>> arr;
    vector<int> temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            temp.push_back(0);
        }
        arr.push_back(temp);
        temp.clear();
    }

    fillabove(s1, s2, n, m, arr);
    int fb[] = fillbelow(inp[2],inp[3],arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}