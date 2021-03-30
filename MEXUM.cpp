#include <iostream>
#include <algorithm>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int* subsum(int a[], int index, int subindex, int sub[], int N)
{
    if(index == N)
    {
        return sub;
    }

    int sub[subindex] = a[index] + subsum(a, index+1, subindex+1, sub, N);
    int sum[subindex] = subsum(a, index+1, subindex, sub, N);
    return sum1+sum2;
}

int main()
{
    int T,N,i,j,k,l,power;
    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>N;
        int a[N],sub[N];
        for(j=0; j<N; j++)
        {
            cin>>a[j];
            sub[j] = 0;
        }
        // power = pow(2,N);
        // int ss[power];

        sol = subsum(a,0,0,sub,N);
    }
    return 0;
}