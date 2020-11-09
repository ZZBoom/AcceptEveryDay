
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
  ListNode *reverse_once_k(ListNode *head, int k) {
    int count = 0;
    auto c_p = head;
    while (c_p != NULL && count < k) {
      c_p = c_p->next;
      count++;
    }
    if (count < k) {
      return head;
    }
    ListNode *tail = NULL, *now = NULL, *pre = NULL;
    auto new_tail = head;
    count = 0;
    while (head != NULL && count < k) {
      now = head;
      head = head->next;
      tail = head;
      if (pre != NULL) {
        now->next = pre;
      }
      pre = now;
      count++;
    }
    new_tail->next = tail;
    return now;
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    auto tail = head;
    ListNode *new_head = head;
    
    new_head = reverse_once_k(head, k);
    if (new_head == NULL) {
      return head;
    }
    auto pre = head;
    while (head->next) {
      auto temp = head->next;
      head = temp;
      auto now_head = reverse_once_k(temp, k);
      pre->next = now_head;
      pre = head;
    }
    return new_head;
  }
};

