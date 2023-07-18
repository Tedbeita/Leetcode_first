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
    vector<int> robtree(TreeNode* cur)
    {
        if(cur == NULL ) return vector<int>{0,0};
        vector<int> left = robtree(cur->left);
        vector<int> right = robtree(cur->right);
        int val1 = cur->val + left[0] + right[0];
        int val2 = max(left[0],left[1]) + max(right[0],right[1]);
        return{val2,val1};
    }
    int rob(TreeNode* root) {
        vector<int> result = robtree(root);
        return max(result[0],result[1]);
    }
};
