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
    int minDiffInBST(TreeNode* root) {
        vector<int> memo;
        Inorder(root, memo);
        int min_diff = memo.back() - memo.front();
        int tmp;

        for (int i=1; i<memo.size(); i++) {
            tmp = memo[i] - memo[i-1];
            if (tmp <= min_diff)
                min_diff = tmp;
        }

        return min_diff;
    }

    void Inorder(TreeNode* root, vector<int>& _memo)
    {
        if (root == NULL) return;

        Inorder(root->left, _memo);
        _memo.push_back(root->val);
        Inorder(root->right, _memo);
    }
};