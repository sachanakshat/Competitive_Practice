#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

#define MAX = INT32_MAX;

using namespace std;
using namespace std::chrono;

int makeanagram(string str1, string str2)
{
    int i;
    int m = str1.size();
    int n = str2.size();
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    int arr[26] = {0};
    int maximum = max(m,n);

    if(maximum == m)
    {
        for(i=0; i<m; i++)
        {
            arr[str1[i]-65]++;
            // cout<<int(str1[i])<<" "<<endl;
        }
        for(i=0; i<n; i++)
        {
            if(arr[str2[i]-65]!=0)
                arr[str2[i]-65]--;
        }
    }
    else
    {
        for(i=0; i<n; i++)
        {
            arr[str2[i]-65]++;
            cout<<int(str2[i])<<endl;
        }
        for(i=0; i<m; i++)
        {
            if(arr[str1[i]-65]!=0)
                arr[str1[i]-65]--;
        }
    }

    for(i=0; i<26; i++)
    {
        cout<<"\n"<<arr[i];
    }
    int sum=0;
    for(i=0; i<26; i++)
        sum+=arr[i];

    return sum;

}

int main()
{
    auto start = high_resolution_clock::now();
    
    string str2 = "bcadeh";
    string str1 = "hea";
    int sol = makeanagram(str1, str2);
    cout<<"\nSolution = "<<sol;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}