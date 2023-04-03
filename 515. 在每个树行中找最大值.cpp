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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<int> result;
        while(!que.empty())
        {
            int size = que.size();
            int max = que.front()->val;
            while(size--)
            {
                TreeNode* node = que.front();
                if(node->val > max) max = node->val;
                que.pop();
                if(node->left != NULL) 
                {
                    que.push(node->left);
                }
                if(node->right != NULL) 
                {
                    que.push(node->right);
                }
            }
            result.push_back(max);
        }
        return result;
    }
};
