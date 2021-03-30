#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void printvector(vector<int> arr)
{
    cout<<"\n";
    int n = arr.size();
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int pairs(int k, vector<int> arr) {
    int n = arr.size();
    int j = n-1, count = 0,index;
    sort(arr.begin(), arr.end());
    printvector(arr);
    cout<<"k = "<<k<<endl;
    // while(i<j)
    // {
    //     cout<<"\ni = "<<i<<" j = "<<j<<endl;
    //     cout<<"Diff = "<<arr[j]-arr[i]<<endl;
    //     if(k>arr[j]-arr[i])
    //     {
    //         cout<<"incremented"<<endl;
    //         i++;
    //     }
    //     else if(k<arr[j]-arr[i])
    //     {
    //         cout<<"Decremented"<<endl;
    //         j--;
    //     }
    //     else
    //     {
    //         cout<<"\nMatched: "<<i<<" and" <<j<<endl;
    //         count++;
    //         i++;
    //         j=n-1;
    //     }
        
    // }

    for(auto i = arr.begin(); i!=arr.end(); i++)
    {
        auto ptr = upper_bound(i, arr.end(), *i+k);
        index = ptr-arr.begin();
        index--;
        while(arr[index] == *i+k)
        {
            cout<<"\nFound at index "<<i-arr.begin()<<" and "<<index<<endl;
            count++;
            index--;
        }
    }
    return count;

}

int main() {
    auto start = high_resolution_clock::now();

    vector<int> arr{1,5,3,4,2};
    int k = 2;
    int sol = pairs(k, arr);
    cout<<"\nThe total number of pairs = "<<sol<<endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}