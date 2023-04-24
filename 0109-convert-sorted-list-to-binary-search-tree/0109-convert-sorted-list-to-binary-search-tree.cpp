/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* Insert(vector<int>& keys,int left,int right){
        if(right < left) return NULL;
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(keys[mid]);
        root->left = Insert(keys,left,mid-1);
        root->right = Insert(keys,mid+1,right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> keys;
        while(head != NULL){
            keys.push_back(head->val);
            head = head->next;
        }

        return Insert(keys,0,keys.size()-1);
    }
};

