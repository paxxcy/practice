// int length(struct ListNode* list){
//     int ret = 1;
    
//     ListNode* curr = list;
//     while(curr!=null){
//         curr = curr.next;
//         ret++;
//     }
    
//     return ret;
// }

// int listToInt(struct ListNode* list){
//     int ret = 0;
    
//     ListNode* curr = list;
//     ret = curr->val;
//     while(curr!=null){
//         ret = ret*10;
//         ret += curr->val;
//         curr = curr->next;
//     }
    
//     return ret;
// }

int length(struct ListNode* list){
    return list==NULL?0:length(list->next)+1;
}

struct ListNode* createListNode(int val,struct ListNode* next){
    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val = val;
    ret->next = next;
    return ret;
}

//n1 contains the longer one
struct ListNode* addTwoNumbersRecurse(struct ListNode* n1, int len1, struct ListNode* n2,int len2){
    //base case
    if(len1==0) return NULL;
    
    //recurse
    struct ListNode* list;
    struct ListNode* ret;
    if(len1>len2){
        //recurse len1 only
        list = addTwoNumbersRecurse(n1->next,len1-1,n2,len2);
        ret = createListNode(n1->val,list);
    }
    else{
        //recurse both and add both
        list = addTwoNumbersRecurse(n1->next,len1-1,n2->next,len2-1);
        ret = createListNode(n1->val+n2->val,list);
    }
    //deal with overflow
    if(ret->next!=NULL && ret->next->val>=10){
        ret->next->val -= 10;
        ret->val++;
    }
    //return
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
    //get the lengths
    int len1 = length(l1);
    int len2 = length(l2);
    
    struct ListNode* ret;
    if(len1>len2)
        ret = addTwoNumbersRecurse(l1,len1,l2,len2);
    else
        ret = addTwoNumbersRecurse(l2,len2,l1,len1);
        
    //deal with the last overflow.
    if(ret->val>=10){
        ret->val -= 10;
        return createListNode(1,ret);
    }
    return ret;
}
