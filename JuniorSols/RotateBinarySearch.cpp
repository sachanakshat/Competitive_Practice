#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void printArray(vector<int> &arr, int n)
{
    cout<<"\n---------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n---------------------------"<<endl;
}

int binarySearch(vector<int> arr, int e, int pivot)
{
    int n = arr.size();
    int low=0,high=pivot, mid;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == e)
            return mid;
        else if(arr[mid]>e)
            high = mid-1;
        else
        {
            low = mid+1;
        }
    }

    low = pivot+1,
    high = n-1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == e)
            return mid;
        else if(arr[mid]>e)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int findPivot(vector<int>& arr, int n)
{
    int s=0, e=n-1;
    int i = (s+e)/2;
    int prev = -1;
    while(arr[i-1]<=arr[i] && s<=e)
    {
        // cout<<"\ns = "<<s<<" e = "<<e;
        if(arr[i]>=arr[s] && ((prev!=-1 && arr[i]>=arr[prev]) || prev==-1) && arr[0]>arr[n-1])
        {
            // cout<<"\nStart index changed";
            s = i+1;
        }
        else
        {
            e=i-1;
            // cout<<"\nEnd index changed";
        }
        prev = i;
        i=(s+e)/2;
    }
    return i;
}

int main()
{
    int n=2;
    cout<<"Enter the size of array: ";
    cout<<n;
    // cin>>n;
    vector<vector<int>> arr;
    vector<int> temp{2,1};
    arr.push_back(temp);
    temp.clear();

    arr.push_back({1,2});
    arr.push_back({1,1,1,1,1});
    arr.push_back({1,2,3,4,5});
    arr.push_back({2,3,4,5,1});
    arr.push_back({2,3,3,3,1});
    arr.push_back({3,4,5,6,7,8,9,10,1,2});
    arr.push_back({6,7,8,9,10,1,2,3,4,5});

    for(int i=0; i<arr.size(); i++)
    {
        n = arr[i].size();
        printArray(arr[i],n);
        int p = findPivot(arr[i], n);
        int foundindex = binarySearch(arr[i], arr[i][(0+n)/2+1], p);
        if(foundindex!=-1)
            cout<<"\nFound at: "<<foundindex;
        else
        {
            cout<<"\nNot found!"<<endl;
        }
        cout<<"\n"<<p<<endl;
    }
    return 0;
}