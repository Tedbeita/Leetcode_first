/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root != NULL) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            while(size--)
            {
                Node* node = que.front();
                que.pop();
                if(size != 0 &&!que.empty()) node->next = que.front();
                if(node->left != NULL) 
                {
                    que.push(node->left);
                }
                if(node->right != NULL) 
                {
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};
