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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        ListNode *nn = head->next, *prev = head, *pprev = NULL;
        bool rem = false;
        while (nn) {
            if (nn->val == prev->val) {
                prev->next = nn->next;
                nn = prev->next;
                rem = true;
            } else {
                if (rem) {
                    if (pprev) {
                        pprev->next = nn;
                        prev = pprev;
                    } else {
                        head = nn;
                        prev = NULL;
                    }
                    rem = false;   
                }
                pprev = prev;
                prev = nn;
                nn = nn->next;
            }
        }
        if (rem) {
            if (pprev) {
                pprev->next = nn;
            } else {
                head = nn;
            }
        }
        return head;
    }
};