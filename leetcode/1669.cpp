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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *indexList1 = list1;
        ListNode *indexList2 = list2;
        ListNode *pre =nullptr;
        int index = 0;
        // delete
        // pre
        // next = indexList1
        while(indexList1) {
            if (index < a) {
                index++;
                pre = indexList1;
                indexList1 = indexList1->next;
            }
            else if (b >= index && index >= a) {
                indexList1 = indexList1->next;
                index++;
            } else {
                break;
            }
        }
        while(indexList2->next) {
            indexList2 = indexList2->next;
        }
        if (pre) {
            pre->next = list2;
            indexList2->next = indexList1;
            return list1;
        } else {
            indexList2->next = indexList1;
            return list2;
        }
    }
};

