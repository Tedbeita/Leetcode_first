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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<double> result;
        while(!que.empty())
        {
            int size = que.size();
            int num = size;
            vector<int> vec;
            double sum = 0;
            while(size--)
            {
                TreeNode* node = que.front();
                vec.push_back(node->val);
                que.pop();
                sum += node->val;
                if(node->left != NULL) 
                {
                    que.push(node->left);
                }
                if(node->right != NULL) 
                {
                    que.push(node->right);
                }
            }
            result.push_back(sum / num);
        }
        return result;
    }
};
