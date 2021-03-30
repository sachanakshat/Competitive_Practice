//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    
    void swap(int &a, int &b)
    {
        int c;
        c = a;
        a = b;
        b = c;
    }
    
    void print(vector<int> & v)
    {
        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int i, j, max;
        int n = nums.size();
        //less than K
        for(i=0; i<n; i++)
        {
            max = nums[i];
            for(j = i+1; j<n; j++)
            {
                if(nums[j]>max)
                {
                    max = nums[j];
                    swap(nums[j], nums[i]);
                }
            }
        }
        //print(nums);
        
        return nums[k-1];
    }
};