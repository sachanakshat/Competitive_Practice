#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

#include <bits/stdc++.h>

using namespace std;

void show(int arr[], int n)
{
    cout<<"\n------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n------------------------"<<endl;
}

int bitscore(int n)
{
    int h,t,o;
    o = n%10;
    n/=10;
    t = n%10;
    n/=10;
    h = n%10;
    n/=10;
    int maxi = max(h,max(t,o));
    int mini = min(h,min(t,o));
    int sum = maxi*11 + mini*7;
    return sum%100;
}

int main()
{
    int n,inp,i;
    cin>>n;
    int *bs = (int*)malloc(sizeof(int)*n);
    // int bs[n];
    for(i=0; i<n; i++)
    {
        cin>>inp;
        bs[i] = bitscore(inp);  //Bitscores calculated
    }

    vector<int> oddb,evenb;
    for(i=0; i<n; i++)
    {
        if(i%2==0)
        {
            evenb.push_back(bs[i]);
        }
        else
        {
            oddb.push_back(bs[i]);
        }
    }
    //Odd and even indices separated

    int o[10]={0}, e[10]={0}, oe[10];
    int siz1 =  oddb.size();
    int siz2 = evenb.size();
    for(i=0; i<siz1; i++)
        o[oddb[i]/10]++;
    for(i=0; i<siz2; i++)
        e[evenb[i]/10]++;
    //Number of digits in odd and even arrays

    for(i=0; i<10; i++)
    {
        int t1 = o[i];
        int t2 = e[i];
        oe[i] = (t1*(t1-1))/2 + (t2*(t2-1))/2;
        if(oe[i]>=2)
            oe[i] = 2;
    }

    int sum=0;
    for(i=0;i<10; i++)
    {
        sum+=oe[i];   
    }
    cout<<sum;
    return 0;
}