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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        int deep = 0;
        while(!que.empty())
        {
            int size = que.size();
            while(size--)
            {
                TreeNode* node = que.front();
                que.pop();
                if(node->left == NULL && node->right == NULL) 
                {
                    deep++;
                    return deep;
                }
                if(node->left != NULL) 
                {
                    que.push(node->left);
                }
                if(node->right != NULL) 
                {
                    que.push(node->right);
                }
            }
            deep++;
        }
        return deep;
    }
};
