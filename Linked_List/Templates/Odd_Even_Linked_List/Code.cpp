/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* odd_head = head;
    struct ListNode* even_head = (head) ? head->next : NULL;

    struct ListNode *odd = odd_head;
    struct ListNode *even = even_head;
    struct ListNode *last_odd = NULL;
    while (odd && even) {
        struct ListNode *odd_next = NULL;
        struct ListNode *even_next = NULL;
        
        if (odd->next) {
            odd_next = odd->next->next;
        }
        if (even->next) {
            even_next = even->next->next;
        }

        odd->next = odd_next;
        even->next = even_next;

        last_odd = odd;
        odd = odd_next;
        even = even_next; 
    }

    if (odd)
        last_odd = odd;

    if (last_odd)
        last_odd->next = even_head;
    
    return odd_head;
}
