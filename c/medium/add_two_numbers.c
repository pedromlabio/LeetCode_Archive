/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addDigit(struct ListNode* l1, struct ListNode* l2, int carry){
    if (l1 == NULL && l2 == NULL && carry == 0)
    {
        return NULL; //nothing else to be done, end recursion
    }
    
    int sum = carry; //start sum by adding carry to it
    if (l1 != NULL)
    {
        sum+=l1->val;
        l1 = l1->next;
    }
    if (l2 != NULL)
    {
        sum+=l2->val;
        l2 = l2->next;
    }

    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = sum % 10; //getting the single digit
    newNode->next = addDigit(l1, l2, sum/10); //recursion
    
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addDigit(l1, l2, 0);
}
