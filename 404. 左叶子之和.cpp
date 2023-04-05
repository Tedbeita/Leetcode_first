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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left ==NULL && root->right == NULL ) return 0;
        int leftvalue = sumOfLeftLeaves(root->left);
        if(root->left != NULL && !root->left->left && !root->left->right)
        {
            leftvalue = root->left->val;
        }
        int rightvalue = sumOfLeftLeaves(root->right);
        int sum = rightvalue + leftvalue;
        return sum;
    }
};
