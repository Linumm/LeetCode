/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> route_val1;
        vector<TreeNode*> route_val2;
        RouteSave(root, p->val, route_val1);
        RouteSave(root, q->val, route_val2);
        TreeNode* descend;
        bool loop_escape = false;
        
        for (int i = route_val1.size()-1; i>=0; i--) {
            if (loop_escape == true)
                break;
            for (int j = route_val2.size()-1; j>=0; j--) {
                if (route_val1[i] == route_val2[j]) {
                    descend = route_val2[j];
                    loop_escape = true;
                    break;
                }
            }
        }
        
        return descend;
    }
    
    void RouteSave(TreeNode* root, int p, vector<TreeNode*>& node_route)
    {
        if (root == NULL) return;
        node_route.push_back(root);
        if (p == root->val) return;
        
        else if (p > root->val)
            RouteSave(root->right, p, node_route);
        else if (p < root->val)
            RouteSave(root->left, p, node_route);
    }
};