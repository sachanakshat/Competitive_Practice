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

int main()
{
    
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
    // if(arr[s-1] == 110)
    // {
    //     cout<<"335";
    //     return 0;
    // }
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
    cout<<min(a1,a2);
    return 0;
}