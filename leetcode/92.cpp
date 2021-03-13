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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        auto now = head;
        int num = 1;
        ListNode *pre = nullptr;
        while(num < left) {
            pre = now;
            now = now->next;
            num++;
        }
        auto new_head = new ListNode();
        auto tail = now;
        while(num <= right) {
            auto next = now->next;
            now->next = new_head->next;
            new_head->next = now;
            now = next;
            num++;
            tail->next = next;
        }
        if (pre) {
            pre->next = new_head->next;
        } else {
            head = new_head->next;
        }
        delete new_head;
        return head;
    }
};
