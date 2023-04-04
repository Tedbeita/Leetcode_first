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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        
        while(!que.empty())
        {
            TreeNode* leftnode = que.front();
            que.pop();
            TreeNode* rightnode = que.front();
            que.pop();
            if(!leftnode && !rightnode)
            {
                continue;
            }

            if((!leftnode || !rightnode ||(leftnode->val != rightnode->val)))
            {
                return false;
            }
            que.push(leftnode->left);
            que.push(rightnode->right);
            que.push(leftnode->right);
            que.push(rightnode->left);

        }
        return true;
    }
};
