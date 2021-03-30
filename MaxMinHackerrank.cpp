#include <bits/stdc++.h>

using namespace std;

int maxMin(int k, vector<int> arr) {
    int n = arr.size();
    int i;
    sort(arr.begin(), arr.end());
    min = arr[k-1]-arr[0];
    for(i=0; i<=n-k; i++)
    {
        if(min>(arr[i+k-1]-arr[i]))
            min = arr[i+k-1]-arr[i];
    }
    return min;
}

int main()
{
    int T,k;
    vector<int> arr;
    cin>>T;
    cin>>k;
    return 0;
}