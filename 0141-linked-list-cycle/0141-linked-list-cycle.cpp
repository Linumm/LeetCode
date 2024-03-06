/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> node_mem;
        ListNode *tmp = head;

        while (true) {
            if (!tmp) // nullptr (tail-over)
                return false;
            if (node_mem.find(tmp) == node_mem.end()) {
                node_mem[tmp] = tmp->val;
                tmp = tmp->next;
                continue;
            }
            return true;
        }
        return false;
    }
};