#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void printTallyArray(int arr[])
{
    cout<<"\n";
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    auto start = high_resolution_clock::now();

    int N;
    string str;
    vector<string> v;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>str;
        v.push_back(str);
    }
    int count = 0;

    for(int i=0; i<N; i++)
    {

        for(int j=i+1; j<N; j++)
        {
            int tally[10] = {0};
            
            for(int k=0; k<v[i].size(); k++)
            {
                
                if(tally[v[i][k]-48]==0)
                    tally[v[i][k]-48] = 1;
            }

            for(int k=0; k<v[j].size(); k++)
            {
                
                if(tally[v[j][k]-48]==0)
                    tally[v[j][k]-48] = 1;
            }
            
            int flag=0;
            for(int j=0; j<10; j++)
                if(tally[j]==0)
                    flag=1;
            if(flag!=1)
                count++;
        }
    }

    cout<<"Answer = "<<count<<endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}