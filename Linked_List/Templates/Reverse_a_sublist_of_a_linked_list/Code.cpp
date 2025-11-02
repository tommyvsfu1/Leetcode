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
    struct ListNode *prev = NULL;

    int start = 0;
    struct ListNode *left_prev = NULL;
    struct ListNode *right_next = NULL;
    while (curr) {
        if (start == left) {
            left_prev = prev;
        }
        if (start == right) {
            right_next = curr->next;
        }

        if (start >= left && start <= right) {
            struct ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }

        if (start == right) {
            break;
        }
        start++;
    }

    if (left_prev) {
        struct ListNode *left_node = left_prev->next;
        left_prev->next = prev;
        left_node->next = right_next;
    }

    return dummy.next;
}
