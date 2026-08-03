/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *result=(int *)malloc(sizeof(int)*(numsSize-k+1));
    int *deque=(int *)malloc(sizeof(int)*numsSize);
    int front=0, rear=-1;
    int index=0;

    for(int i=0;i<numsSize;i++){
        if(front<=rear && deque[front]<=i-k)
          front++;

        while(front<=rear && nums[deque[rear]]<=nums[i])
          rear--;

        deque[++rear]=i;

        if(i>=k-1)
          result[index++]=nums[deque[front]];
    }
    *returnSize=index;
    free(deque);
    return result;
}