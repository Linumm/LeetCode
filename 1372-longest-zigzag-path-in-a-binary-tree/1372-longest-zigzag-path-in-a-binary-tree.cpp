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
    int max_len = 0;

    int longestZigZag(TreeNode* root) {
        Traversal(root, -1, 0);
        Traversal(root, 1, 0);
        return max_len;
    }
    void Traversal(TreeNode* root, int direction, int len)
    {
        // Direction : left(-1), right(1)
        if (root == NULL) return;
        
        max_len = max(max_len, len);

        if (direction == -1) {
            Traversal(root->left, -1, 1);
            Traversal(root->right, 1, ++len);
        }
        else if (direction == 1) {
            Traversal(root->left, -1, ++len);
            Traversal(root->right, 1, 1);
        }
    }
    
};

//Recursively traversing