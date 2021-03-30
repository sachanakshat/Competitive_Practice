#include <iostream>

using namespace std;

int * insertion(int a[], int n)
{
    int key,i;
    for(int j = 2; j<n; j++)
    {
        key = a[j];
        i = j-1;
        while(key<a[i] && i>0)
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
    return a;
}

int main()
{
    int arr[] = {2,46,86,18,62,8,9,5,89,5,68,94};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion(arr, n);
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}