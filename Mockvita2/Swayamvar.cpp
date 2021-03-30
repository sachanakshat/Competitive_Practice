#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

bool matched(vector<char>& b, vector<char>& g)
{
    int flag=0;
    vector<char> temp;
    while(!g.empty())
    {
        if(b[0] == g[0])
        {
            b.erase(b.begin());
            g.erase(g.begin());
            flag=1;
            break;
        }
        else
        {
            // cout<<g[0]<<endl;
            temp.push_back(g[0]);
            g.erase(g.begin());
        }
    }
    int s = temp.size();
    for(int i=0; i<s; i++)
    {
        g.push_back(temp[i]);
    }
    // g.insert(g.end(), temp.begin(), temp.end());
    temp.clear();
    if(flag==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n,i;
    string brides,grooms;
    cin>>n;
    cin>>brides;
    cin>>grooms;
    vector<char> b,g;

    for(i=0; i<n; i++)
    {
        b.push_back(brides[i]);
        g.push_back(grooms[i]);
    }

    for(i=0; i<n; i++)
    {
        if(!matched(b,g))
        {
            cout<<n-i;
            return 0;
        }
    }
    cout<<"0";
    return 0;
}