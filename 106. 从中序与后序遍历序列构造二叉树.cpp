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
    TreeNode* traversal(vector<int>& inorder,vector<int>& postorder)
    {
        if(postorder.size() == 0) return NULL;
        
        //后序的最后一个元素，就是根节点
        int rootvalue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootvalue);

        if(postorder.size() == 1) return root;

        //找到中序遍历的切割点
        int delimiterIndex;
        for(delimiterIndex = 0;delimiterIndex < inorder.size();delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootvalue) break;
        }

        //分割前后，左闭右开
        vector<int> leftinorder(inorder.begin(),inorder.begin()+delimiterIndex);
        vector<int> rightinorder(inorder.begin() +  delimiterIndex + 1,inorder.end());
        postorder.resize(postorder.size() - 1);
        //切割后续数组
        vector<int> leftpostorder(postorder.begin(),postorder.begin() + leftinorder.size());
        vector<int> rightpostorder(postorder.begin() + leftinorder.size(),postorder.end());

        root->left = traversal(leftinorder,leftpostorder);
        root->right = traversal(rightinorder,rightpostorder);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder,postorder);
    }
};
