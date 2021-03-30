//https://practice.geeksforgeeks.org/problems/check-if-two-strings-are-k-anagrams-or-not/1

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;

bool areKAnagrams(string str1, string str2, int k)
{
    int m = str1.size();
    int n = str2.size();
    int s1=0,s2=0;

    if(m!=n)
        return false;
    
    int a1[26] = {0};
    int a2[26] = {0};
    for(auto i:str1)
        a1[i-97]+=1;
    for(auto i:str2)
        a2[i-97]+=1;
    
    for(int i=0; i<26; i++)
    {
        if(a1[i]!=0 || a2[i]!=0)
        {
            if(a1[i]>a2[i])
            {
                s1+=a1[i]-a2[i];
            }
            else
            {
                s2+=a2[i]-a1[i];
            }
            
        }
    }

    if(s1==s2)
        if(s1<=k)
            return true;
        else
        {
            return false;
        }
    return false;
}

int main()
{
    auto start = high_resolution_clock::now();

    string str1 = "fodr";
    string str2 = "gork";
    if(areKAnagrams(str1,str2,2))
        cout<<"\nStrings are k-anagrams";
    else
    {
        cout<<"\nStrings are not k-anagrams";
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}