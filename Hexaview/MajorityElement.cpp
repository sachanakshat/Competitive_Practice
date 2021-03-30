#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printmap(map<int, int> mp)
{
    for(auto it = mp.begin(); it != mp.end(); ++it)
    {
        cout << it->first << " " << it->second<<endl;
    }
}

int main()
{
    // auto start = high_resolution_clock::now();

    int n,i,j,k,ele;
    cin>>n;
    int arr[n];

    map<int,int> freq;

    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(i=0; i<n; i++)
    {

        if(freq.find(arr[i]) == freq.end())
        {
            freq.insert(pair<int, int>(arr[i], 0));
        }
        else
        {
            freq[arr[i]]++;
        }
        
    }
    // printmap(freq);

    int flag = 0;

    for (auto itr = freq.begin(); itr != freq.end(); ++itr)
    { 
        if(itr->second >=n/2)
        {
            cout<<itr->first<<endl;
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        cout<<"-1"<<endl;

    return 0;
}