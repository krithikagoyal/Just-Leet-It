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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(), *tmp = head, *prev;
        less->next = head;
        
        prev = less;
                
        ListNode* hhead = less;
        while (tmp) {
            if (tmp->val < x) {
                if (less->next != tmp) {
                    ListNode* nn = less->next;
                    less->next = tmp;
                    prev->next = tmp->next;
                    tmp->next = nn;
                    tmp = prev->next;
                } else {
                    prev = tmp;
                    tmp = tmp->next;
                }
                less = less->next;
            } else {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        
        return hhead->next;
    }
};