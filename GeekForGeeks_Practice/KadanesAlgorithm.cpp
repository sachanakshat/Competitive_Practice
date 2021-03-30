//https://leetcode.com/problems/maximum-subarray/submissions/

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int maxSubArray(vector<int>& nums)
{
    int cmax = nums[0], gmax = nums[0],i;
    for(i = 1; i<nums.size(); i++)
    {
        cmax = max(nums[i], cmax + nums[i]);
        if(cmax>gmax)
            gmax = cmax;
    }
    return gmax;
}

int main()
{
    auto start = high_resolution_clock::now();

    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int sol = maxSubArray(nums);
    cout<<sol<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}