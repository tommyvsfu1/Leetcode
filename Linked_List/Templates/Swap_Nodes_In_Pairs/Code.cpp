/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *curr = &dummy;

    while (curr) {
        if (curr->next && curr->next->next) {
            struct ListNode *next = curr->next;
            struct ListNode *next_next = curr->next->next;
            curr->next = next_next;
            next->next = next_next->next;
            next_next->next = next;

            curr = curr->next->next;
        }
        else {
            curr = NULL;
        }
    }

    return dummy.next;
}
