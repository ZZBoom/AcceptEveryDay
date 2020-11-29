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

    ListNode* middleNode(ListNode* head) {
        auto slow = head;
        auto fast = head;
        ListNode* pre = NULL;
        while(fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre != NULL) {
            pre->next = NULL;
        }
        return slow;
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        auto mid = middleNode(head);
        auto list1 = head;
        auto list2 = reverseList(mid);
        while(list1 != NULL && list2 != NULL) {
            auto next1 = list1->next;
            auto next2 = list2->next;
            list1->next = list2;
            if (next1 != NULL) {
                list2->next = next1;
            }
            list1 = next1;
            list2 = next2;
        }
    }
};
