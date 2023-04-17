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
    bool isValidBST(TreeNode* root) {
        vector<int> memo;
        PushInorder(root, memo);
        for (int i=1; i<memo.size(); i++)
            if (memo[i-1] >= memo[i]) return false;
        return true;
    }

    void PushInorder(TreeNode* _root, vector<int>& _memo)
    {
        if (_root == NULL) return;
        PushInorder(_root->left, _memo);
        _memo.push_back(_root->val);
        PushInorder(_root->right, _memo);
    }
};

//Since Inorder traversal results the increasing order in BST, I used this. 