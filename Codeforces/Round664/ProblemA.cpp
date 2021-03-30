#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

// int ckpal(vector<int>& balls)
// {
//     if(balls[0] ==0 && balls[1] ==0 && balls[2] ==0 && balls[3] ==0)
//     {
//         return 1;
//     }
//     if(balls[0] ==0 || balls[1] ==0 || balls[2] ==0)
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
    
// }

int ckpal(vector<int> balls)
{
    int min = balls[0];
    for(int i=0; i<3; i++)
    {
        if(balls[i]<min)
            min = balls[i];
    }
    for(int i=0; i<3; i++)
    {
        balls[i] = balls[i]-min;
    }
    balls[3] = balls[3] + min*3;
    int odds = 0;
    for(int i=0; i<4; i++)
    {
        if(balls[i]%2!=0)
            odds++;
    }
    if(odds>1)
        return 0;
    else
    {
        return 1;
    }
    
}

int main()
{
    auto start = high_resolution_clock::now();

    int T,ch,i,j;
    cin>>T;
    vector<int> balls;
    for(i=0; i<T; i++)
    {
        for(j=0; j<4; j++)
        {
            cin>>ch;
            balls.push_back(ch);
        }
        if(ckpal(balls))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        
        balls.clear();
    }
    return 0;
}