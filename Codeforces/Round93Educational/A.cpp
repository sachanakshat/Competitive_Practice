#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void check(int* arr, int n)
{
    int j,k,l, flag=0;

    for(j=0; j<n-2; j++)
    {
        for(k=j+2; k<n; k++)
        {
            if(arr[j]+arr[j+1]<arr[k])
            {
                flag = 1;
                cout<<j+1<<" "<<j+2<<" "<<j+3<<endl;
                return;
            }
        }
    }
    if(flag == 0)
        cout<<"-1"<<endl;
}

int main()
{
    int T,n,i,j,k,l,m;
    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n;
        int * arr = (int*)malloc(sizeof(int)*n);
        for(j=0; j<n; j++)
        {
            cin>>arr[j];
        }
        check(arr, n);
        
        free(arr);

    }
    return 0;
}