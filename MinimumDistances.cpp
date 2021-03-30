#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int minimumDistances(vector<int> a) {
    int min = a.size() + 1;
    unordered_map<int, int> m;
    for(int i=0; i<a.size(); i++)
    {
        if(m.find(a[i]) == m.end())
            m[a[i]] = i;
        else
        {
            if(i-m[a[i]]<min)
                min = i-m[a[i]];
            m[a[i]] = i;
        }
    }
    if(min == a.size()+1)
        return -1;
    return min;
}


int main()
{
    auto start = high_resolution_clock::now();
    vector<int> que{7,1,3,4,1,7};
    cout<<"\n"<<minimumDistances(que)<<"\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}
