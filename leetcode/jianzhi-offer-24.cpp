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
    ListNode* reverseList(ListNode* head) {
        ListNode *now = NULL, *pre = NULL;
        while(head) {               // 1          2
            auto next = head->next; // 2          3 
            head->next = pre;       // 1->NULL    2->1->NULL
            pre = head;             // 1          2
            head = next;            // 2          3
        }
        return pre;
    }
};
