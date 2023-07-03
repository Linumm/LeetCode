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
    ListNode* swapNodes(ListNode* head, int k) {
        /*
        0) Check the length of list
        1) Find two target
        3) Swap
        */
        if (head->next == NULL) return head; // case of len 1

        int len = 0;
        ListNode* tmp = head;
        ListNode* node_1;
        while (tmp != NULL) {
            len++;
            if (len == k) node_1 = tmp;
            tmp = tmp->next;
        }
        tmp = head;

        int target_from_end = len - k + 1;

        for (int i=1; i<target_from_end; i++) {
            tmp = tmp->next;
        }
        ListNode* node_2 = tmp;
        swap(node_1->val, node_2->val);

        return head;
    }
};