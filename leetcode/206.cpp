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
        auto now = head;
        ListNode* pre = NULL;
        while(now != NULL) {
            auto next = now->next;
            now->next = pre;
            pre = now;
            head = pre;
            now = next;
        }
        return head;
    }
};
