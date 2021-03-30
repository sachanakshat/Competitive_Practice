#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

#include <bits/stdc++.h>

using namespace std;

int divide(int maxi, int mini)
{
    if(maxi == mini)
        return 1;
    int d1 = max(maxi-mini, mini);
    int a = divide(d1,maxi-d1);
    // int s = a+1;
    return a+1;
}
int main()
{
    int P,Q,R,S;
    int sum=0;
    cin>>P>>Q>>R>>S;
    for(int i=P; i<=Q; i++)
    {
        for(int j=R; j<=S; j++)
        {
            sum+=divide(max(i,j),min(i,j));
        }
    }

    cout<<sum;
    return 0;
}