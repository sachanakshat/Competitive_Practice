//https://leetcode.com/problems/group-anagrams/submissions/
//https://leetcode.com/submissions/detail/361959478/testcase/

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;

bool checkanagram(string str1, string str2)
{
    int arr[26] = {0},i;
    int m = str1.size();
    int n = str2.size();
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    if(m == max(m, n))
    {
        for(i=0; i<m; i++)
            arr[str1[i]-65]++;
        for(i=0; i<n; i++)
        {
            if(arr[str2[i]-65]!=0)
                arr[str2[i]-65]--;
        }
    }
    else
    {
        for(i=0; i<n; i++)
            arr[str2[i]-65]++;
        for(i=0; i<m; i++)
        {
            if(arr[str1[i]-65]!=0)
                arr[str1[i]-65]--;
        }
    }
    int sum=0;
    for(i=0; i<26; i++)
        sum+=arr[i];
    if(sum == 0)
        return true;
    else
        return false;
    
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    int n = strs.size(),i,j;
    int visited[n] = {0};
    vector<vector<string>> sol;
    vector<string> substr;
    for(i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            substr.push_back(strs[i]);
            for(j=i+1; j<n; j++)
            {
                if(visited[j] == 0 && checkanagram(strs[i], strs[j]))
                {
                    visited[j] = 1;
                    substr.push_back(strs[j]);
                }
            }
        }
        if(substr.size()!=0)
            sol.push_back(substr);
        substr.clear();
    }
    return sol;
}

int main()
{
    auto start = high_resolution_clock::now();
    
    string str2 = "bcadeh";
    string str1 = "hea";
    vector<string> strs;
    // strs.push_back("cat");
    // strs.push_back("dog");
    // strs.push_back("tac");
    // strs.push_back("god");
    // strs.push_back("act");
    // ["eat","tea","tan","ate","nat","bat"]
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    vector<vector<string>> sol = groupAnagrams(strs);
    for(int i=0; i<sol.size(); i++)
    {
        for(int j=0; j<sol[i].size(); j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }

    // cout<<"\n"<<checkanagram("eat", "beat")<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}