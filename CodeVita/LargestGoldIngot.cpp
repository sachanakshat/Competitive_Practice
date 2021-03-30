#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
// using namespace std::chrono;

// void print(vector<int> vect)
// {
//     cout<<"\n-------------------------------"<<endl;
//     for(int i=0; i<vect.size(); i++)
//     {
//         cout<<vect[i]<<" ";
//     }
//     cout<<"\n-------------------------------"<<endl;
// }

// void print(int * arr, int n)
// {
//     cout<<"\n-------------------------------"<<endl;
//     for(int i=0; i<n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<"\n-------------------------------"<<endl;   
// }

int main()
{
    // auto start = high_resolution_clock::now();

    int L,b,h,i,j;
    cin>>L;
    cin>>b;
    cin>>h;
    // int l[L];
    long * l = (long*)malloc(sizeof(long)*L);
    for(i=0; i<L; i++)
    {
        cin>>l[i];
    }
    //Find total volume
    long long total_vol=0;
    for(i=0; i<L; i++)
    {
        total_vol+=l[i]*b*h;
    }
    // cout<<"Total volume = "<<total_vol<<endl;

    //Initializing the helper array
    // int hel[L];
    long * hel = (long*)malloc(sizeof(long)*L);
    for(i = 1; i<L-1; i++)
    {
        if(l[i]<l[i-1] && l[i]<l[i+1])
            hel[i] = 1;
        else
            hel[i] = 0;
    }
    if(l[0]<l[1])
        hel[0] = 1;
    else
    {
        hel[0] = 0;
    }
    if(l[L-1]<l[L-2])
        hel[L] = 1;
    else
    {
        hel[L] = 0;
    }
    //Helper array init finish
    // print(hel, L);

    int count;//Counting the number of valid bars
    long long max=0;//Keeping count of maximum vol
    int vol;//temp volume variable

    //Iterating 1s
    for(i = 0; i<L; i++)//Select the min stick
    {
        if(hel[i]==0)
            continue;
        count = 0;
        // cout<<"Calculating for "<<i<<"..."<<endl;
        for(j=0; j<L; j++)//Iterate for that min stick
        {
            if(l[j]<l[i] && j>=i)
            {
                //Game over. Count the progress. Skip to next I
                vol = count*l[i]*b*h;
                // cout<<"Game over volume = "<<vol<<endl;
                if(vol>max)
                    max = vol;
                // cout<<"Game over Max = "<<max<<endl;
                break;
            }
            else if(l[j]<l[i] && j<i)
                continue;
            else
            {
                count++;
                vol = count*l[i]*b*h;
                // cout<<"Iterate volume = "<<vol<<endl;
                if(vol>max)
                    max = vol;
                // cout<<"Iterate Max = "<<max<<endl;
            }
            
        }
    }
    // int modulo = pow(10,9)+7;

    // cout<<"Maximum volume = "<<max<<endl;
    cout<<(total_vol-max)%1000000007<<endl;
    
    

    // cout<<"\nMaximum value of subarrays = "<<maxsum<<endl;
    
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}