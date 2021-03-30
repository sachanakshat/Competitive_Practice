#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int * merged = (int*)malloc(sizeof(int)*(m+n));
        
        int i=0, j=0, k=0;

        i=m-1, j=n-1, k=m+n-1;

        while(i>=0 && j>=0)
        {
            if(nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        while(i>=0)
            nums1[k--] = nums1[i--];
        while(j>=0)
            nums1[k--] = nums2[j--];
        
        // while(i<m && j<n)
        // {
        //     if(nums1[i] < nums2[j])
        //         merged[k++] = nums1[i++];
        //     else
        //         merged[k++] = nums2[j++];
        // }
        
        // while(i<m)
        //     merged[k++] = nums1[i++];
        // while(j<n)
        //     merged[k++] = nums2[j++];

        //I tried both space separated form and this kind of format. Nothing works!
        
        // for(k=0; k<m+n-1; k++)
        // {
        //     nums1[k] = merged[k];
        // }

        cout<<"[";
        for(k=0; k<m+n-1; k++)
            cout<<nums1[k]<<",";
        cout<<nums1[k]<<"]";
        
    }
};

int main()
{
    auto start = high_resolution_clock::now();
    // int a[10] = {15,45,32,41,65,12,95,23,25,65};
    vector<int> arr{1,1,1,2,2};
    // vector<int> arr{2,4,1,5,3};
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};

    Solution obj;

    obj.merge(nums1, 3, nums2, 3);


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}