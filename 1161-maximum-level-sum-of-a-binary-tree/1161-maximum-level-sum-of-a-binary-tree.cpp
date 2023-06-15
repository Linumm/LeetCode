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
    int maxLevelSum(TreeNode* root) {
        int max_sum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int ans_lv = 0;
        vector<int> level_sum;

        while (!q.empty()) {
            int q_size = q.size(); // every each level, queue size is fixed
            int sum = 0;
            for (int i=0; i<q_size; i++) {
                TreeNode* current= q.front();
                q.pop();
                sum += current->val;
                if (current->left != NULL) q.push(current->left);
                if (current->right != NULL) q.push(current->right);
            }
            level_sum.push_back(sum);
        }

        for (int i=0; i<level_sum.size(); i++) {
            if (level_sum[i] > max_sum) {
                max_sum = level_sum[i];
                ans_lv = i;
            }
        }

        return ans_lv+1; // level is counted from 1
    }
};