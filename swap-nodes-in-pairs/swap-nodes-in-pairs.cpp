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
    ListNode* swapPairs(ListNode* head) {
        ListNode* nn = new ListNode();
        nn->next = head;
        ListNode* tmp = nn, *hhead = head;
        
        while (tmp->next && tmp->next->next) {
            ListNode* nnext = tmp->next->next;
            tmp->next->next = nnext->next;
            nnext->next = tmp->next;
            tmp->next = nnext;
            tmp = tmp->next->next;
            // cout << tmp->val << endl;
            if (hhead == head) {
                hhead = nnext;
            }
        }
        
        return hhead;
    }
};