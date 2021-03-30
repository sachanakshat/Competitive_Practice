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

void printvec(vector<int> arr)
{
    cout<<"\n-------------------------"<<endl;
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n-------------------------"<<endl;
}

int main()
{
    auto start = high_resolution_clock::now();
    
    string str,temp="";
    vector<int> arr;
    getline(cin,str);
    str = str+' ';
    int s = str.size(),i;
    int a1=0, a2=0;
    for(i=0; i<s; i++)
    {
        if(str[i]==' ')
        {
            arr.push_back(stoi(temp));
            temp="";
        }
        else
        {
            temp+=str[i];
        }
    }
    sort(arr.begin(), arr.end());
    // printvec(arr);
    s = arr.size();
    a1+=arr[s-1];
    // cout<<arr[s-1]<<" ";
    a2+=arr[s-2];
    // cout<<arr[s-2]<<" ";
    for(i=s-3; i>=0; i--)
    {
        if(a1 == min(a1,a2))
        {
            a1+=arr[i];
            // cout<<arr[i]<<" ";
        }
        else
        {
            a2+=arr[i];
            // cout<<arr[i]<<" ";
        }
        
    }
    cout<<max(a1,a2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}