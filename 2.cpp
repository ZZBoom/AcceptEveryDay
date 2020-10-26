struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    auto now_node = head;
    int flag = 0;
    while (l1 || l2) {
      int a = l1 ? l1->val : 0;
      int b = l2 ? l2->val : 0;
      l1 = l1 ? l1->next : l1;
      l2 = l2 ? l2->next : l2;
      auto new_node = new ListNode(0);
      new_node->val = (a + b + flag) % 10;
      flag = (a + b + flag) / 10;
      now_node->next = new_node;
      now_node = now_node->next;
    }
    if (flag) {
      auto new_node = new ListNode(0);
      new_node->val = flag;
      now_node->next = new_node;
    }
    return head->next;
  }
};

int main() {}
