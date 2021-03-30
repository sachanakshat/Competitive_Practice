//Question: https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
//Test cases: https://hr-testcases-us-east-1.s3.amazonaws.com/1636/input01.txt?AWSAccessKeyId=AKIAJ4WZFDFQTZRGO3QA&Expires=1595153578&Signature=IDViWKmataUE0%2B2mW%2F0wtb9BUwY%3D&response-content-type=text%2Fplain
//Output: https://hr-testcases-us-east-1.s3.amazonaws.com/1636/output01.txt?AWSAccessKeyId=AKIAJ4WZFDFQTZRGO3QA&Expires=1595153584&Signature=wW6eG4jgEswqj2Xs4qYPw7xZ2sU%3D&response-content-type=text%2Fplain

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void printvector(long arr[], int n)
{
    cout<<"\n-------------------------"<<endl;
    for(int i=0; i<n; i++)
    {

        cout<<arr[i]<<" ";
    }
    cout<<"\n-------------------------"<<endl;
}

void printvector(vector<int>& arr)
{
    cout<<"\n-------------------------"<<endl;
    for(int i=0; i<arr.size(); i++)
    {

        cout<<arr[i]<<" ";
    }
    cout<<"\n-------------------------"<<endl;
}

long arrayManipulation(int n, vector<vector<int>> queries) {

    vector<long> arr(n,0);
    long max = 0;

    for(int i=0; i<queries.size(); i++)
    {
        
    }





    for(int i=0; i<queries.size(); i++)
    {
        for(int j=queries[i][0]; j<=queries[i][1]; j++)
        {
            arr[j-1]+=queries[i][2];
            // printvector(arr,n);
            if(arr[j-1]>max)
                max = arr[j-1];
        }
    }

    return max;

}

int main()
{
    auto start = high_resolution_clock::now();

    int n,que,p;
    vector<int> temp;
    vector<vector<int>> queries;
    cin>>n;
    cin>>que;
    for(int i=0; i<que; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>p;
            temp.push_back(p);
        }
        queries.push_back(temp);
        temp.clear();
    }
    int sol = arrayManipulation(n, queries);
    cout<<"\nMax value = "<<sol<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}