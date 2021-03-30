#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int rbinary(int a[], int low, int high, int x)
{
    if(low<=high)
    {
        int mid = (low+high)/2;
        if(a[mid] == x)
            return mid;
        else if(x<a[mid])
            return rbinary(a, low, mid-1, x);
        else if(x>a[mid])
            return rbinary(a, mid+1, high, x);
    }
    return 0;
}

int main()
{
    auto start = high_resolution_clock::now();
    int a[] = {2,8,14,15,36,42,71,82,126,428,564,956,1024};
    int l=0, h = sizeof(a)/sizeof(a[1]), check=0;
    int x = 1024;
    if((check = rbinary(a, l, h, x)))
        cout<<"Element found at index: "<<check<<"\n";
    else
        cout<<"Element not found! \n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<<duration.count()<<endl;
}