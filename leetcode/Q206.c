/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    //base case
    if(head==NULL || head->next == NULL) return head;
    
    //recurse
    struct ListNode* newHead = reverseList(head->next);
    
    //reverse
    head->next->next = head;
    head->next = NULL;
    
    //return
    return newHead;
}
