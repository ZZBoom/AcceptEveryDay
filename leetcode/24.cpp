class Solution {
public:
  // 1->2->3->4
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *new_head = new ListNode();
    auto new_head_p = new_head;
    while (head != nullptr && head->next != nullptr) {
      auto p = head->next->next;
      new_head->next = head->next;
      new_head->next->next = head;
      head = p;
      new_head = new_head->next->next;
      new_head->next = NULL;
    }
    while (head != nullptr) {
      new_head->next = head;
      head = head->next;
    }
    return new_head_p->next;
  }
};
