/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *curr = &dummy;
    
    for (int i = 0; i < left-1; i++) {
        curr = curr->next;
    }

    struct ListNode *left_prev = curr;
    curr = curr->next;

    for (int i = 0; i < right-left; i++) {
        struct ListNode *next = curr->next;
        curr->next = next->next;
        next->next = left_prev->next;
        left_prev->next = next;
    }

    return dummy.next;
}
