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
    vector<vector<int>> paths;
    vector<int> path_nodes;
    int sum = 0;
    void dfs(TreeNode* root, int target_sum)
    {
        // Like pre-order traversing
        if (root == NULL)
            return;
        path_nodes.push_back(root->val);
        sum+= root->val;
        
        if (sum == target_sum && !root->left && !root->right)
            paths.push_back(path_nodes);

        dfs(root->left, target_sum);
        dfs(root->right, target_sum);

        // When out from call stack, pop current node value and diff the sum
        path_nodes.pop_back();
        sum-= root->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return paths;
        
        dfs(root, targetSum);
        
        return paths;
    }
};