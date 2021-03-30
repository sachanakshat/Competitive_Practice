#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void print(vector<vector<int>> vect)
{
    for(int i = 0; i< vect.size(); i++)
    {
        for(int j = 0; j<vect[0].size(); j++)
            cout<<vect[i][j]<<" ";
        cout<<"\n";   
    }
}

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] > v2[0]; 
}

int main()
{
    auto start = high_resolution_clock::now();
    vector<vector<int>> arr{{5,1},
                    {2,1},
                    {1,1},
                    {8,1},
                    {10,0},
                    {5,0}};
    cout<<"\n";
    print(arr);
    sort(arr.begin(), arr.end(), sortcol);
    cout<<"\n";
    print(arr);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}