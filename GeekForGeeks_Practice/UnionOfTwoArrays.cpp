//https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
UNION code----

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int m,n,p=0,q=0;
        
        m = nums1.size();
        n = nums2.size();
        
        vector<int> sol;
        while(p<m && q<n)
        {
            if(nums1[p]<nums2[q])
                sol.push_back(nums1[p++]);
            else
                sol.push_back(nums2[q++]);
        }
        
        while(p<m)
        {
            sol.push_back(nums1[p++]);
        }
        while(q<n)
            sol.push_back(nums2[q++]);
        
        return sol;
        
    }
};

---
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int m,n,p=0,q=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        m = nums1.size();
        n = nums2.size();
        
        vector<int> sol;
        while(p<m && q<n)
        {
            if(nums1[p]==nums2[q])
            {
                sol.push_back(nums1[p++]);
                q++;
            }
            else if(nums1[p]<nums2[q])
            {
                p++;
             }
            else
                q++;
        }
        
        return sol;
        
    }

    void printVector(vector<int>& v)
    {
        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    Solution obj;
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};
    vector<int> sol;
    sol = obj.intersect(nums1,nums2);
    obj.printVector(sol);
    return 0;
}

