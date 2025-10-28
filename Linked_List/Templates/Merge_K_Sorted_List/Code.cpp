/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* Merge(struct ListNode* p1, struct ListNode* p2) {
    if (p1 == NULL && p2 == NULL) return NULL;
    if (p1 == NULL) return p2;
    if (p2 == NULL) return p1;

    struct ListNode* head = NULL;
    if (p1->val <= p2->val) {
        head = p1;
        p1->next = Merge(p1->next, p2);
    }
    else {
        head = p2;
        p2->next = Merge(p1, p2->next);
    }

    return head;
}
struct ListNode* dfs(struct ListNode** p, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return p[start];

    int mid = start + (end - start) / 2;

    struct ListNode* L1 = dfs(p, start, mid);
    struct ListNode* L2 = dfs(p, mid+1, end);

    return Merge(L1, L2);
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    return dfs(lists, 0, listsSize-1);
}
