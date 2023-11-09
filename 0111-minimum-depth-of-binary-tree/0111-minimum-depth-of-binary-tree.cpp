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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        TreeNode* current = NULL;
        int min = 0;
        while (!q.empty()) {
            current = q.front().first;
            min = q.front().second;
            q.pop();

            if (current->left == NULL && current->right == NULL)
                return min;
            else {
                if (current->left != NULL)
                    q.push({current->left, min+1});
                if (current->right != NULL)
                    q.push({current->right, min+1});
            }
        }

        return 1;
    }
};

//오랜만에 하려니 이것도 힘들더..