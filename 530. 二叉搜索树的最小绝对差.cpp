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
class Solution {
public:
    TreeNode* pre = NULL;
    int m = INT_MAX;
    void getmin(TreeNode* root,int val)
    {
        if(root == NULL) return;
        getmin(root->left,m);
        if(!pre == NULL && m > abs(pre->val - root->val))
        {
            m = abs(pre->val - root->val);
        }
        pre = root;
        getmin(root->right,m);
    }
    int getMinimumDifference(TreeNode* root) {
        getmin(root,m);
        return m;
    }
};
