#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void swap(int a[], int A, int B)
{
    int temp = a[A];
    a[A] = a[B];
    a[B] = temp;
}

void show(int a[])
{
    // cout<<"\nArray:\n";
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
/*
void rheapify(int a[], int n, int root)
{
    if(root>n)
        return;
    int lchild=2*root, rchild=2*root+1;
    if(lchild<=n && a[root-1]<a[lchild-1])
    {
        cout<<"\n\tRoot= "<<root<<"\n";
        cout<<"Left child= "<<lchild<<"\tRight child= "<<rchild<<"\n";
        cout<<"\nSwap left: "<<a[root-1]<<" and "<<a[lchild-1]<<"\n";
        swap(a, root-1, lchild-1);
        show(a,n);
        //rheapify(a,n,lchild);
    }
    cout<<"\nHeapifying left child: "<<lchild<<"\n";
    rheapify(a,n,lchild);

    if(rchild<=n && a[root-1]<a[rchild-1])
    {
        cout<<"\n\tRoot= "<<root<<"\n";
        cout<<"Left child= "<<lchild<<"\tRight child= "<<rchild<<"\n";
        cout<<"\nSwap right: "<<a[root-1]<<" and "<<a[rchild-1]<<"\n";
        swap(a, root-1, rchild-1);
        show(a,n);
        //rheapify(a,n,rchild);
    }
    cout<<"\nHeapifying right child: "<<rchild<<"\n";
    rheapify(a,n,rchild);
}

void heapifyBottom(int a[], int n, int root)
{
    if(root<1)
        return;
    int lchild=2*root, rchild=2*root+1,max=root;
    if(lchild<=n)
        if(a[lchild-1]>a[max-1])
            max = lchild;
    if(rchild<=n)
        if(a[rchild-1]>a[max-1])
            max = rchild;
    swap(a, max-1, root-1);
    if(max!=root)
        heapifyBottom(a, n, max);
}

void heapify(int a[], int n)
{
    int root,i2;
    for(int i=n; i>=1; i--)
    {
        i2=i;
        root = i/2;
        while(a[root-1]<a[i2-1] && root>0)
        {
            cout<<"\ni2\troot\n";
            cout<<i2<<"\t"<<root;
            cout<<"\nSwap: "<<a[i2-1]<<" and "<<a[root-1]<<"\n";
            swap(a, root-1, i2-1);
            i2 = root;
            root = root/2;
            show(a,n);
        }
    }
}

bool checkArrayHeap(int a[], int n)
{
    vector<int> vect(a, a+n);
    return is_heap(vect.begin(), vect.end());
}
*/
// int merge(vector<int>& arr, int i, int m, int j, int &count)
// {
//     int a1[m-i+1];
//     int a2[j-m];
//     int a,b,c;

//     cout<<"\nMerging: ";
//     for(a=i; a<=m; a++)
//         cout<<arr[a]<<" ";
//     cout<<"and ";
//     for(a=m+1; a<=j; a++)
//         cout<<arr[a]<<" ";
//     cout<<"Size of a1 = "<<m-i+1<<" Size of a2 = "<<j-m<<"\n";

//     for (a = 0; a < m-i+1; a++) 
//         a1[a] = arr[i + a];
//     cout<<"\nArray a1: ";
//     show(a1); 
//     for (a = 0; a < j-m; a++) 
//         a2[a] = arr[m + 1+ a]; 
//     cout<<"\nArray a2: ";
//     show(a2);
    
    
//     for(c=i,a=0,b=0; c<=j;)
//     {
//         while(a<=m-i+1 && b<=j-m)
//         {
//             if(a1[a]>a2[b])
//             {
//                 arr[c++] = a2[b++];
//                 count+=((j-i+1)-c);
//             }
//             else
//             {
//                 arr[c++] = a1[a++];
//             }
//         }

//         if(a<m-i+1)
//             arr[c++] = a1[a++];
//         else
//             arr[c++] = a2[b++];
        
        
//     }

//     return 0;
// }

int inversions(vector<int>& arr, int i, int j, int &count)
{
    if(i==j)
    {
        return arr[i];
    }
    inversions(arr, i, (i+j)/2, count);
    inversions(arr, (i+j)/2+1, j, count);
    merge(arr, i, (i+j)/2, j, count);
    return 0;
}

int countInversions(vector<int> &A) {
    int count = 0;
    inversions(A, 0, A.size()-1, count);
    return count;
}


int main()
{
    auto start = high_resolution_clock::now();
    // int a[10] = {15,45,32,41,65,12,95,23,25,65};
    vector<int> arr{2,4,1,5,3};
    int inversions = countInversions(arr);
    cout<<"\nNumber of inverisons = "<<inversions<<"\n";



    // show(a,n);
    // for(int i=n/2; i>=1; i--)
    // {
    //     heapifyBottom(a, n, i);
    // }
    // cout<<"\nIs array heap? "<<checkArrayHeap(a, n)<<"\n";
    // show(a,10);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}