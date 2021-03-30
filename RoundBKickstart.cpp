#include <iostream> 
#include <vector> 
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T,N,count;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        int J[N];
        for(int j=0; j<N; j++)
        {
            cin>>J[j];
        }
        count=0;
        for(int j=1; j<N-1; j++)
        {
            //cout<<J[j-1]<<" "<<J[j]<<" "<<J[j+1]<<" ";
            if((J[j-1]<J[j]) && (J[j]>J[j+1]))
                count++;
        }
        cout<<count<<"\n";
        // for(int j=0; j<N; j++)
        // {
        //     cout<<J[j]<<" ";
        // }
        // cout<<"\n";
    }
}