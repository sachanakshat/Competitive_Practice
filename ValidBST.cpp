#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
bool isBSTutil(TreeNode* root, int minValue, int maxValue)
{
    if(root == NULL)
        return true;
    if(root->val>=minValue && root->val<maxValue && isBSTutil(root->left, minValue, root->val) && isBSTutil(root->right, root->val, maxValue))
        return true;
    else
        return false;

}
 
int Solution::isValidBST(TreeNode* A) {
    if(isBSTutil(A, -2147483647, 2147483647) == true)
        return 1;
    else
        return 0;
}


int main()
{
    auto start = high_resolution_clock::now();
    
    // int n[] = {11,4,2,5,1,5,-1,-1,-1,-1,-1,-1};
    int n[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };

    int size = sizeof(n)/sizeof(n[0]); 
    TreeNode* root = insertLevelOrder(n, root, 0, size); 
    inOrder(root);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"\nExecution time: "<<duration.count() <<" microseconds"<<endl;
    return 0;
}