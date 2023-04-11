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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL ) return root;
        if (root->val == key)
        {
            if(root->left == NULL && root->right == NULL) 
            {
                delete root;
                return NULL;
            }
            else if(root->left == NULL && root->right != NULL) 
            {
                return root->right;
            }
            else if(root->left !=NULL && root->right == NULL)
            {
                return root->left;
            }
            else if(root->left != NULL && root->right != NULL)
            {
                TreeNode* cur = root->right;
                while(cur->left != NULL)
                {
                    cur = cur->left;
                }   
                cur->left = root->left;
                TreeNode* temp = root;
                root=root->right;
                delete temp;
                return root;
            }
        }
        if(root->val > key) root->left = deleteNode(root->left,key);
        if(root->val < key) root->right = deleteNode(root->right,key);
        return root;

    }
};
