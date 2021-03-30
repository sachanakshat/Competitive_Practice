#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void print(vector<int> vect)
{
    cout<<"\n-------------------------------"<<endl;
    for(int i=0; i<vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<"\n-------------------------------"<<endl;
}

void print(int * arr, int n)
{
    cout<<"\n-------------------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n-------------------------------"<<endl;   
}

int main()
{
    int T, n,i,j,val;
    cin>>T;
    vector<int> arr;
    for(i=0; i<T; i++)
    {
        cin>>n;
        for(j = 0; j<n; j++)
        {
            cin>>val;
            arr.push_back(val);
        }

        int num = 2, diff=arr[0]-arr[1];
        set<int> s;
        for(j=1; j<n-1; j++)
        {
            cout<<"in loop";
            int newdiff = arr[j]-arr[j+1];
            if(newdiff==diff)
            {
                num+=1;
            }
            else
            {
                cout<<num<<endl;
                s.insert(num);
                num = 2;
                diff = newdiff;
            }
            s.insert(num);
        }
        for (auto it = s.cbegin(); it != s.cend(); it++) {
		std::cout << *it << ' ';
	    }
        cout<<"Case #"<<i+1<<": "<<*s.rbegin()<<endl;;
        arr.clear();
    }
}