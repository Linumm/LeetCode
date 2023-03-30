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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* search_node = head;
        int list_len = 1;
        while (search_node->next != nullptr) {
            search_node = search_node->next;
            list_len++;
        }
        search_node = head;
        
        for (int i=0; i<list_len-n-1; i++) 
            search_node = search_node->next;
        
        if (list_len == n) {
            search_node = head->next;
            delete head;
            return search_node;
        }
        else {
            ListNode* tmp = search_node->next;
            search_node->next = tmp->next;
            delete tmp;
        }


        return head;
    }
};