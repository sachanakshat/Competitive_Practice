#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void print(vector<int> vect)
{
    cout<<"\n-------------------------------"<<endl;
    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<"\n-------------------------------"<<endl;
}

void print(int * arr, int n)
{
    cout<<"\n-------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n-------------------------------"<<endl;   
}

int longestSeq(vector<int> &arr)
{
    int max = 0;
    int val = arr[0];
    int cmax=1;
    int j, n = arr.size()+1;
    // cout<<"N = "<<n<<endl;

    for(j=0; j<n-1; j++)
    {
        cout<<"j = "<<j<<"& cmax = "<<cmax<<endl;
        if(arr[j]!=val || j==n-2)
        {
            cout<<arr[j]<<"!="<<val<<endl;
            max = (cmax>max)?cmax:max;
            cout<<"MAX = "<<max<<endl;
            cout<<"cmax = 1"<<endl;
            cmax = 1;
            cout<<"val = "<<arr[j]<<endl;
            val = arr[j];
        }
        else
        {
            cmax++;
        }
    }

    // for(j=0; j<n-1; j++)
    // {
    //     // cout<<"j= "<<j<<endl;
    //     if(arr[j]!=val || j==n-2)
    //     {
    //         // cout<<"val not matched or end at "<<j<<endl;
    //         val = arr[j];
    //         if(cmax>max)
    //         {
    //             // cout<<"cmax = "<<cmax<<" > "<<"max = "<<max<<endl;
    //             max = cmax;
    //             cmax=1;
    //         }
    //         continue;
    //     }
    //     // cout<<"cmax++"<<endl;
    //     cmax++;
    // }
    return max;
}

int main()
{

    int T,n,val,i,j,d,max,cmax,flag;
    vector<int> arr, diff, diff0, diff1;
    cin>>T;
    for(i=0; i<T; i++)
    {
        cin>>n;
        //Array insertion
        for(j=0; j<n; j++)
        {
            cin>>val;
            arr.push_back(val);
        }

        //Diff array calculation
        for(j=0; j<n-1; j++)
        {
            d = abs(arr[j]-arr[j+1]);
            diff.push_back(d);
        }

        //diff0 array calculation
        for(j=0; j<n-1; j++)
        {
            d = (arr[j]<arr[j+1]?1:0);
            diff0.push_back(d);
        }

        //diff1 array calculation
        for(j=0; j<n-1; j++)
        {
            d = (arr[j]<=arr[j+1]?1:0);
            diff1.push_back(d);
        }

        //diff diff0 fusion
        for(j=0; j<n-1; j++)
        {
            diff0[j] = diff[j] - diff0[j];
        }

        //diff diff1 fusion
        for(j=0; j<n-1; j++)
        {
            diff1[j] = diff[j] - diff1[j];
        }
        print(arr);
        print(diff);
        print(diff0);
        print(diff1);

        int d0 = longestSeq(diff0);
        int d1 = longestSeq(diff1);
        cout<<"d0 = "<<d0<<" d1 = "<<d1<<endl;

        cout<<"Case #"<<i+1<<": "<<min(d0,d1)+1<<endl;
        print(arr);
        print(diff);
        arr.clear();
        diff.clear();
        diff0.clear();
        diff1.clear();
    }
    
    return 0;
}