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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* tmp = head;
        
        while (tmp != nullptr) {
            nodes.push_back(tmp);
            tmp = tmp -> next;
        }
        
        int idx = nodes.size() / 2;
        return nodes[idx];
    }
};