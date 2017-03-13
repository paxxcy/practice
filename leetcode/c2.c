struct ListNode* createListNode(int val,struct ListNode* next){
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = val;
    ret->next = next;
    return ret;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* curr = NULL;
    
    struct ListNode* left = l1;
    struct ListNode* right = l2;
    
    int overflow = 0;
    while(left!=NULL || right !=NULL){
        //add the two numbers
        int sum = (left!=NULL?left->val:0) + (right!=NULL?right->val:0) + overflow;
        
        //create a new node
        curr = createListNode(sum%10,NULL);
        overflow = sum/10;
        
        //advance
        left = left!=NULL?left->next:NULL;
        right = right!=NULL?right->next:NULL;
        if(head==NULL)
            head = curr;
        else
            prev->next = curr;
        prev = curr;
    }
    if(overflow>0){
        prev->next = createListNode(overflow,NULL);
    }
    
    return head;
}

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//     //create
//     struct ListNode* head = NULL;
//     struct ListNode* prev = NULL;
//     struct ListNode* curr;
//     //link
//     struct ListNode* left = l1;
//     struct ListNode* right = l2;
    
//     int sum;
//     int overflow = 0;
//     while(left!=NULL || right !=NULL){
//         //create
//         curr = (struct ListNode*)malloc(sizeof(struct ListNode));
//         //link
//         if(prev==NULL)
//             head = curr;
//         else
//             prev->next = curr;

//         //save the sum
//         int sum = (left!=NULL?left->val:0) + (right!=NULL?right->val:0) + overflow;
//         curr->val = sum%10;
        
//         //advance
//         left = (left!=NULL?left->next:NULL);
//         right = (right!=NULL?right->next:NULL);
//         prev = curr;
//         overflow = sum/10;
//     }
//     if(overflow>0){
//         //create the last digit if needed
//         //create
//         curr = (struct ListNode*)malloc(sizeof(struct ListNode));
//         //link
//         if(prev==NULL)
//             head = curr;
//         else
//             prev->next = curr;
//         curr->val = overflow;
//     }
    
//     return head;
// }
