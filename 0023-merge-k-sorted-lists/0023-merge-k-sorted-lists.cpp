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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> every_val;
        ListNode* ptr;
        for (int i=0; i<lists.size(); i++) {
            ptr = lists[i];
            while (ptr != NULL) {
                every_val.push_back(ptr->val);
                ptr = ptr->next;
            }
        }
        if (every_val.size() == 0) return NULL;
        // Sort the elements in vector (in anyway, but I'll use c++ given method)
        sort(every_val.begin(), every_val.end());

        ListNode* new_list = new ListNode(every_val[0]);
        if (every_val.size() < 2) {
            return new_list;
        } 
        
        ptr = new_list;
        for (int i=1; i<every_val.size(); i++) {
            ptr = InsertFromTail(ptr, every_val[i]);
        }
        
        return new_list;
    }

    ListNode* InsertFromTail(ListNode* tail, int val)
    {
        ListNode* new_node = new ListNode(val);

        tail->next = new_node;

        return tail->next;
    }
};