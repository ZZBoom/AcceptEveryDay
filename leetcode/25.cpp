
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
  ListNode *reverseK(ListNode *head, int k) {
    ListNode *now = nullptr, *pre = nullptr;
    // 1->2->3
    int count = 0;
    while(count < k) {        // 1            2
      auto next = head->next; // 2            3
      head->next = pre;       // 1->null      2->1->null
      pre = head;             // 1            2
      head = next;            // 2            3
      count++;
    }
    return pre;
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1) {
      return head;
    }
    ListNode *now = head, *pre = nullptr;
    // 1->2->3->4->5   2
    while(now) {
      auto reverseHead = now;     // 1   3
      int count = 0;
      while (now && count < k) {  // 1
        count++;
        now = now->next;
      }
      // now 3->4->5
      if (count == k) {
        auto newHead = reverseK(reverseHead, k);  // 2->1  4->3
        if (pre) {
          pre->next = newHead;  // 2->1->4->3->null
        } else {
          head = newHead;       // 2->1
        }
      } else {
        pre->next = reverseHead;// 3->5
        break;
      }
      pre = reverseHead;       // 1
    }
    return head;
  }
};

