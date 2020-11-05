#include <assert.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int get_length(ListNode *head) {
    int num = 0;
    while (head != nullptr) {
      head = head->next;
      num++;
    }
    return num;
  }

  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto length = get_length(head);
    auto new_head = new ListNode();
    auto cur = new_head;
    // 1 2 3
    for (int i = 0; i < length - n; i++) {
      if (i == 0) {
        cur->next = head;
      }
      cur = cur->next;
    }
    if (cur->next) {
      cur->next = cur->next->next;
    } else {
      cur->next = head->next;
    }
    return new_head->next;
  }
};

int main() {

}
