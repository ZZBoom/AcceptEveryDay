/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//输入: head = 3->5->8->5->10->2->1, x = 5
//输出: 3->1->2->10->5->5->8
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode *newHead = NULL, *now = head, *newPre = NULL, *pre = NULL;
      while(now) {                          // 3 5 8 5  10 2 1
        auto next = now->next;              // 5 8 5 10  2 1 NULL
        if (x > (now->val)) {               //
          if (newPre == NULL) {             
            newHead = newPre = now;         // 3
          } else {
            now->next = NULL;               // 1->NULL
            newPre->next = now;             // 3->2->1->NULL
            newPre = now;                   // 1
          }
          now = next;                       // null 
        } else {
          if (pre == NULL) {              
            head = now;                     // 5
          } else {
            pre->next = now;
          }
          pre = now;                        // 5 8 5  10
          now = next;                       // 8 5 10  2
        }
      }
      if (newPre) {
        if (pre) {
          newPre->next = head;
          pre->next = NULL;
        }
        return newHead;
      }
      return head;
    }
};


