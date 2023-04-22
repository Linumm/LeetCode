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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        
        //Make it as a circle
        ListNode* tmp = head;
        int length = 1;
        while (tmp->next != NULL) {
            tmp = tmp->next;
            length++;
        }
        tmp->next = head;

        k = k % length; // for case of k >= length

        int start_idx = length - k;

        ListNode* result = head;
        ListNode* tail = head; // To cut circle

        for (int i=0; i<start_idx-1; i++)
            tail = tail->next;
        result = tail->next;
        tail->next = NULL;

        return result;
    }
};
