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
        if (head == NULL) return head;
        
        int n = 0;

        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr) {
            prev = curr;
            curr = curr->next;
            n++;
        }
        prev->next = head;

        k = k % n; // 重要
        int target = n - k;
        curr = head;
        prev = NULL;
        for (int i = 0; i < target; i++) {
            ListNode *next = curr->next;
            prev = curr;
            curr = next;
        }

        prev->next = NULL;
        return curr;
    }
};
