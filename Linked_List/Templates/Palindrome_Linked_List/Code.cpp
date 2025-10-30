/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct ListNode *curr = slow;
    struct ListNode *prev = NULL;
    while (curr) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode *p1 = head;
    struct ListNode *p2 = prev;

    while (p2) {
        if (p2->val != p1->val) return false;
        p2 = p2->next;
        p1 = p1->next;
    }

    return true;
}
