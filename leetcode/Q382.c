/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    struct ListNode* head;
} Solution;

/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
Solution* solutionCreate(struct ListNode* head) {
	srand(0);
	Solution* ret = (Solution*)malloc(sizeof(Solution));
	ret->head = head;
	return ret;
}

int listLength(struct ListNode* list){
	return list==NULL ? 0 :listLength(list->next) + 1;
}
int getValue(struct ListNode* list, int i){
	assert(i >= 0);
	return i == 0 ? list->val:getValue(list->next, i - 1);
}

int randomInteger(int max) {
	long end = (RAND_MAX/max) * max;
	long i;
	while( (i = rand()) >= end );
	return (int)(i % max);
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
	int length = listLength(obj->head);
	return getValue(obj->head, randomInteger(length));
}

void solutionFree(Solution* obj) {
	free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 * solutionFree(obj);
 */
