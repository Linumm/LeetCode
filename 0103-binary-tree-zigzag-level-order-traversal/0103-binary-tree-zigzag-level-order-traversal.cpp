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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        //=================== Normal case
        queue<TreeNode*> q;
        bool reverse_v = false;
        q.push(root);

        while(!q.empty()) {
            int q_size = q.size();
            vector<int> v;
            
            for (int i=0; i<q_size; i++) {
                TreeNode* tmp = q.front();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);

                v.push_back(tmp->val);
                q.pop();
            }
            if (reverse_v)
                reverse(v.begin(), v.end());
            reverse_v = !reverse_v; 
            ans.push_back(v);
        }
        return ans; 

    }
};