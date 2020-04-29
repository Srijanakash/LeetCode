/*
Given the root of a binary tree, consider all root to leaf paths: 
paths from the root to any leaf.  (A leaf is a node with no children.)
A node is insufficient if every such root to leaf path intersecting this node has sum strictly less than limit.
Delete all insufficient nodes simultaneously, and return the root of the resulting binary tree.

Example 1:

Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
Output: [1,2,3,4,null,null,7,8,9,null,14]
Example 2:

Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
Output: [5,4,8,11,null,17,4,7,null,null,null,5]
 
Example 3:

Input: root = [1,2,-3,-5,null,4,null], limit = -1
Output: [1,null,-3,4]
 
Note:

The given tree will have between 1 and 5000 nodes.
-10^5 <= node.val <= 10^5
-10^9 <= limit <= 10^9
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    int dfs(TreeNode *root,int sum,int limit)
    {
        if(!root->left && !root->right)
            return sum+root->val;
        int left=root->left?dfs(root->left,sum+root->val,limit):INT_MAX;
        int right=root->right?dfs(root->right,sum+root->val,limit):INT_MAX;
        if (left < limit) 
            root->left = nullptr;
        if (right < limit) 
            root->right = nullptr;
        return left < INT_MAX && right < INT_MAX ? max (left, right) : min(left, right);
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) 
    {
        if(!root)
            return NULL;
        return dfs(root,0,limit)<limit?NULL:root;
        
    }
};
