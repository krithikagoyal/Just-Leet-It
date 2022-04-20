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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        int numNodes = 1;
        ListNode* n = head;
        while (n->next) {
            numNodes++;
            n = n->next;
        }
        k = numNodes - (k % numNodes);
        k %= numNodes;
        if (k == 0) {
            return head;
        }
        n->next = head;
        n = head;
        for (int i = 0; i < k - 1; i++) {
            n = n->next;
        }
        head = n->next;
        n->next = NULL;
        return head;
    }
};