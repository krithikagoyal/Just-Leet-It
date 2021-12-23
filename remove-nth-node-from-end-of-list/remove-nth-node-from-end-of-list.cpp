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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        ListNode* tmp = head;
        while (tmp) {
            num++;
            tmp = tmp->next;
        }
        
        int toRemove = num - n + 1;
        
        if (toRemove == 1) {
            head = head->next;
        } else {
            num = 1;
            tmp = head;
            ListNode* prev;
            while (num != toRemove) {
                num++;
                prev = tmp;
                tmp = tmp->next;
            }
            
            prev->next = tmp->next;
        }
        return head;
    }
};