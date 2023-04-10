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
//利用了递归的办法，并且定义了双指针，如果当前的指针大于前一个指针的，那就是
class Solution {
public:
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        if(root == NULL)  return true;
        bool left = isValidBST(root->left);
        if(!pre == NULL && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left&&right;
    }
};
