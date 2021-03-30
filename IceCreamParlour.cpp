#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void printmap(multimap<int, int> mp)
{
    int n = mp.size();
    cout<<"\nValue\tKey"<<endl;
    for(auto it:mp)
    {
        cout<<it.first<<"\t"<<it.second<<endl;
    }
}

void whatFlavors(vector<int> cost, int money) {
    multimap<int,int> mp;
    int i;
    for(i=0; i<cost.size(); i++)
    {
        // if(mp.find(cost[i]) == mp.end())
            mp.insert(pair<int,int>(cost[i],i+1));
    }
    printmap(mp);

    for(i = 0; i<cost.size(); i++)
    {
        pair<int,int> pr(cost[i], mp.lower_bound(cost[i])->second);
        mp.erase(mp.lower_bound(cost[i]));
        // mp.erase(mp.lower_bound(cost[i]));
        printmap(mp);
        auto it = mp.find(money-cost[i]);
        if(it != mp.end())
        {
            cout<<i+1<<" "<<it->second<<endl;
            break;
        }
        mp.insert(pr);
    }
}

int main()
{
    auto start = high_resolution_clock::now();

    vector<int> cost{2,2,4,3};
    int money =4;

    whatFlavors(cost,money);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}