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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        root = DeleteImpl(root, key);
        return root;
    }
    
    TreeNode* DeleteImpl(TreeNode* root, int key)
    {
        if (root == NULL) return NULL;
        
        if (key < root->val)
            root->left = DeleteImpl(root->left, key);
        else if (key > root->val)
            root->right = DeleteImpl(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }
            else if (!root->left && root->right) {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            else if (root->left && !root->right) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            
            // Find a successor which is the smallest element among bigger elements
            TreeNode* successor = root->right;
            while (successor && successor->left) 
                successor = successor->left;
            
            root->val = successor->val;
            root->right = DeleteImpl(root->right, successor->val);
        }
        
        return root;
    }
};