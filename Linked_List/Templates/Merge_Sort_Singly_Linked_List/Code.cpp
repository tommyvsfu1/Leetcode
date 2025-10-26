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
    ListNode *merge(ListNode *a, ListNode *b) {
        if (a == NULL && b == NULL) return NULL;
        if (a == NULL) return b;
        if (b == NULL) return a;

        ListNode *res = NULL;
        if (a->val <= b->val) {
            res = a;
            res->next = merge(a->next, b);
        }
        else {
            res = b;
            res->next = merge(a, b->next);
        }
        return res;
    }
    ListNode *getMiddle(ListNode *left) {
        if (left == NULL) return NULL;
        
        ListNode *slow = left;
        ListNode *fast = left->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    ListNode* mergeSort(ListNode *node) {
        if (node == NULL || node->next == NULL) return node;

        ListNode *mid = getMiddle(node);

        ListNode *left = mergeSort(node);
        ListNode *right = mergeSort(mid);

        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
