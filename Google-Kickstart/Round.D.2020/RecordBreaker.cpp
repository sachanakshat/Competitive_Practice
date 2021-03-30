#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<vector>


using namespace std;

int main()
{
    int T, i,n,j;
    long long int max, sol;
    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n;
        max=-1;
        sol=0;  //Solutions initialized to 0
        long long int *V = (long long int*)malloc(n * sizeof(long long int));
        for(j=0; j<n; j++)
        {
            cin>>V[j];
        }
        max=-1;
        for(j=0; j<n; j++)
        {
            if(j!=n-1)
            {
                if(max < V[j] && V[j+1]<V[j])
                {
                    sol++;
                }
            }
            else
            {
                if(max<V[j])
                {
                    sol++;
                }
            }
            if(max<V[j])
                max = V[j]; //MAX set for the test case
        }
        free(V);
        cout<<sol<<endl;
    }
    return 0;
}