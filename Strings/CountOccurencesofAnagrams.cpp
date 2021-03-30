//https://www.geeksforgeeks.org/anagram-substring-search-search-permutations/
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<chrono>


using namespace std;
using namespace std::chrono;

bool checkanagram(string str1, string str2)
    {
        int arr[26] = {0},i;
        int m = str1.size();
        int n = str2.size();
        if(m!=n)
            return false;
        
        transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
        transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
        
        for(i=0; i<m; i++)
            arr[str1[i]-65]++;
        for(i=0; i<n; i++)
            if(arr[str2[i]-65]!=0)
                arr[str2[i]-65]--;
        
        int sum=0;
        for(i=0; i<26; i++)
            sum+=arr[i];
        if(sum == 0)
            return true;
        else
            return false;

    }

int main()
{
    auto start = high_resolution_clock::now();

    string str1 = "forxxorfxdofr";
    string str2 = "for";
    int a1[26] = {0};
    int a2[26] = {0};
    int m = str1.size();
    int n = str2.size();
    int s1=0, s2=0;

    unordered_set<char> set;

    for(int i=0;i<n; i++)
        set.insert(str2[i]);
    
    for(int i=0; i<n; i++)
    {
        if()
    }












    for(int i=0; i<n; i++)
    {
        a2[str2[i]-97]++;
        s1++;
    }

    for(int i=0; i<n; i++)
    {
        a1[str1[i]-97]++;
        if()
    }

    if(s==0)
        cout<<"Found at index 0";

    for(int i=1; i<m-n+1; i++)
    {
        a1[str1[i-1]-97]--;
        a1[str1[i+n-1]-97]++;
    }



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