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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> keys;
        InorderTraversal(root, keys);
        return keys[k-1];
    }
    void InorderTraversal(TreeNode* root, vector<int>& key_save)
    {
        if (root == NULL) return;

        InorderTraversal(root->left, key_save);
        key_save.push_back(root->val);
        InorderTraversal(root->right, key_save);
    }
};