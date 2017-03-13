typedef struct{
    int* data;
    int length;
} Solution;
int randomInteger(int max){
    long end = (RAND_MAX/max) * max;
    long i;
    while( (i=rand())>=end );
    return (int)(i%max);
}
Solution* solutionCreate(int* nums, int numsSize){
    srand(time(NULL));
    Solution* ret = (Solution*)malloc(sizeof(Solution));
    ret->data = nums;
    ret->length = numsSize;
    return ret;
}
int solutionPick(Solution* obj, int target) {
    //find number of duplicates
    int count = 0;
    for(int i=0;i<obj->length;i++){
        if(obj->data[i]==target){
            count++;
        }
    }
    int randomIndex = randomInteger(count);
    count=0;
    for(int i=0;i<obj->length;i++){
        if(obj->data[i]==target){
            if(randomIndex==count++){
                //return obj->data[i];
                return i;
            }
        }
    }
    return 0;
}
void solutionFree(Solution* obj) {
    free(obj);
}
/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);
 * solutionFree(obj);
 */
