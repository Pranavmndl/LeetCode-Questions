int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalsum=nums[0];
    int currentMax=nums[0];
    int maximumSum=nums[0];

    int currentMin=nums[0];
    int minimumSum=nums[0];

    for(int i=1; i<numsSize; i++){
        if(nums[i]>currentMax+nums[i]){
            currentMax=nums[i];
        }else{
            currentMax=currentMax+nums[i];
        }
        if(currentMax>maximumSum){
            maximumSum=currentMax;
        }
                if (nums[i]<currentMin+nums[i]) {
            currentMin=nums[i];
        } else {
            currentMin=currentMin+nums[i];
        }
        if (currentMin<minimumSum) {
            minimumSum=currentMin;
    }
    totalsum=totalsum+nums[i];
 }
if(maximumSum<0){
    return maximumSum;
}
int circularSum=totalsum-minimumSum;
if(maximumSum>circularSum){
    return maximumSum;
}else{
    return circularSum;
}
}

