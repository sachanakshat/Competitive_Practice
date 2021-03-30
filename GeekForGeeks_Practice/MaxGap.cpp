https://leetcode.com/problems/maximum-gap/submissions/

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int maximumGap(vector<int>& nums) {
        
        int max = 0, diff, mdiff;
        sort(nums.begin(), nums.end());
        if(nums.size()<2)
            return 0;
        mdiff = nums[1] - nums[0];
        
        for(int i=0; i<nums.size()-1; i++)
        {
            diff = nums[i+1] - nums[i];
            if(mdiff<diff)
                mdiff = diff;
        }
        return mdiff;
        
    }

int main()
{
    auto start = high_resolution_clock::now();

    vector<int> nums{3,6,9,1};
    int sol = maximumGap(nums);
    cout<<sol<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}