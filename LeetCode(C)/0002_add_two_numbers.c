#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* newListNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(struct ListNode);

    node->val = val;
    node->next = NULL;

    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head = NULL;
    struct ListNode *node = NULL;
    int carry = 0;
    int x, y, z;

    head = newListNode(0);
    node = head;
    
    while (l1 != NULL || l2 != NULL) {
        x = l1 != NULL ? l1->val : 0;
        y = l2 != NULL ? l2->val : 0;
        z = x + y + carry;
        carry = z / 10;
        z %= 10;

        node->next = newListNode(z);
        node = node->next;

        if (l1 != NULL)
            l1 = l1->next;

        if (l2 != NULL)
            l2 = l2->next;
    }

    if (carry != 0)
        node->next = newListNode(1);

    return head->next;
}