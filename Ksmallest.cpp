#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int kthsmallest(const vector<int> &A, int B) {
    
    vector<int> C(A.begin(), A.end());
    int i,j,key, min;
    set<int, greater<int>> uset;
    // for(i = 1; i<C.size(); i++)
    // {
    //     key = C[i];
    //     j = i-1;
    //     while(j>=0 && key<C[j])
    //     {
    //         C[j+1] = C[j];
    //         j--;
    //     }
    //     C[j+1] = key;
    // }
    
    int ctr = 0;
    // uset.insert(min);
    
    //Initializing an empty set
    for(i = 0; i<C.size(); i++)
    {
        uset.insert(C[i]);
    }
    //Printing the empty set
    // for(auto i = C.begin(); i!=C.end(); i++)
    // {
        
    //     // cout<<"Printing the empty set\n";
    //     ctr++;
    //     cout<<*i<<" "<<ctr<<"\n";
    //     // cout<<"\n\n\n";
    // }
    
    
    //Finding and removing elements
    for(j=0; j<B; j++)
    {
        min = C[0];
        for(auto i=C.begin(); i!=C.end(); i++)
        {
            // if(uset.find(A[i]) == uset.end() && A[i]<min)
            // {
                
            //     min = A[i];
            //     cout<<min<<" ";
            //     uset.insert(min);
            // }
            
            
            if(*i<min)
            {
                min = *i;
                C.erase(i);
            }
        }
    }
    cout<<C.size()<<"\n";
    for(auto i = C.begin(); i!=C.end(); i++)
    {
        ctr++;
        cout<<*i<<" "<<ctr<<"\n";
    }
    // return C[B-1];
    return min;
    
}

void printvector(vector<int> v)
{
    cout<<"\n";
    int n = v.size();
    for(int i = 0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void printset(set<int> s)
{
    int n = s.size();
    for(auto it:s)
    {
        cout<<it<<" ";
    }
}

void printmap(map<int, pair<int,int>> mp)
{
    cout<<"\nValue1\tValue2\tKey"<<endl;
    map<int,pair<int,int>>::iterator itr;
    for(itr = mp.begin(); itr!= mp.end(); itr++)
    {
        cout<<(itr->second).first<<"\t"<<(itr->second).second<<"\t"<<itr->first<<endl;
    }
}

void swap(vector<int> & arr, int min,int j)
{
    int temp = arr[min];
    arr[min] = arr[j];
    arr[j] = arr[min];
}

int main()
{
    auto start = high_resolution_clock::now();

    vector<int> arr{5,2,1,2,1,2,1};

//     vector<int> arr{1,
// 2,
// 3,
// 4,
// 10,
// 20,
// 30,
// 40,
// 100,
// 200};
//     vector<int> arr{10,
// 100,
// 300,
// 200,
// 1000,
// 20,
// 30};
    // vector<int> arr2(arr.begin(), arr.end());
    int n = arr.size();
    set<int> gaptable;

    map<int, pair<int,int>> mp;
    int k = 2;
    // int sol = kthsmallest(v, k);
    int i, j;

    // for(i=0; i<v.size(); i++)
    // {
    //     if(v[i]<globalmin)
    //         globalmin = v[i];
    // }
    // prevmin = globalmin;
    // cout<<"\nGlobal min = "<<globalmin<<endl;

    // for(int i=0; i<k-1; i++)
    // {
    //     currmin = INT32_MAX;
    //     for(int i=0; i<v.size(); i++)
    //     {
    //         if(v[i]>prevmin && v[i]<currmin)
    //             currmin = v[i];
    //     }
    //     prevmin = currmin;
    // }

    printvector(arr);

    // for(i = 0; i<k; i++)
    // {
    //     min = arr[0];
    //     for(j = 0; j<arr.size()-k; j++)
    //     {
    //         if(arr[j]<arr[min])
    //             min = j;
    //     }
    //     swap(arr, min, j);
    // }

    sort(arr.begin(), arr.end());
    int min, max;
    min = arr[k-1]-arr[0];

    for(i=0; i<=arr.size()-k; i++)
    {
        if(min>(arr[i+k-1]-arr[i]))
            min = arr[i+k-1]-arr[i];
    }
    cout<<"\nMin: "<<min<<endl;
    for(i = 0; i<n-1; i++)
    {
        mp[arr[i+1]-arr[i]] = {arr[i], arr[i+1]};
        // gaptable.insert(arr[i+1]-arr[i]);
    }
    cout<<"\nGap Table:";
    printmap(mp);

    auto itr = mp.begin();
    // min = (itr->first).first;

    advance(itr, k-2);

    // cout<<"\nMin Gap = "<<mp.begin()->second<<" Max Gap = "<<mp.end()->second<<endl;


    // cout<<"\n"<<k<<"th smallest element is "<<arr[arr.size()-1]<<" and difference is "<<arr[arr.size() - k]-arr[arr.size()-1]<<endl;
    printvector(arr);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}
