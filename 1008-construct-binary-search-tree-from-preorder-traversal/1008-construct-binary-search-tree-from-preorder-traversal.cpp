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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder.front());

        for (int i=1; i<preorder.size(); i++)
            Insert(root, preorder[i]);
        return root;
    }

    TreeNode* Insert(TreeNode* root, int _val)
    {
        if (root == NULL) {
            TreeNode* new_node = new TreeNode(_val);
            return new_node;
        }

        if (_val > root->val)
            root->right = Insert(root->right, _val);
        else if (_val < root->val)
            root->left = Insert(root->left, _val);
        
        return root;
    }
};