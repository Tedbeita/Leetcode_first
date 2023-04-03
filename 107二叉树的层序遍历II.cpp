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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<vector<int>> result;
        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            while(size--)
            {
                TreeNode* node = que.front();
                vec.push_back(node->val);
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
            result.push_back(vec);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
