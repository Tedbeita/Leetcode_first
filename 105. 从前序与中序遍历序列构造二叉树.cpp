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
    TreeNode* traversal(vector<int>& preorder,vector<int>& inorder)
    {
        if(preorder.size() == 0) return NULL;
        //取前序数组第一个是做根节点的值
        int rootval = preorder[0];
        TreeNode* root = new TreeNode(rootval);
        //遍历中序找到左右
        int delimiterIndex = 0;
        for(delimiterIndex = 0;delimiterIndex < inorder.size();delimiterIndex++)
        {
            if(inorder[delimiterIndex] == rootval) break;
        }

        //分割中序遍历的左右
        vector<int> leftinorder(inorder.begin(),inorder.begin() + delimiterIndex);
        vector<int> rightinorder(inorder.begin() + delimiterIndex+ 1,inorder.end());

        //分割前序遍历的左右
        vector<int> leftpreorder(preorder.begin() + 1,preorder.begin()+1+delimiterIndex);
        vector<int> rightpreorder(preorder.begin() + 1 +delimiterIndex,preorder.end());
        root->left = traversal(leftpreorder,leftinorder);
        root->right = traversal(rightpreorder,rightinorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0 || preorder.size() == 0) return NULL;
        return traversal(preorder,inorder);
    }
};
