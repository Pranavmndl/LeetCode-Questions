/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    return (*(int *)b) - (*(int *)a);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int *unique = (int *)malloc(sizeof(int) * numsSize);
    int *freq = (int *)calloc(numsSize, sizeof(int));
    int uniqueCount = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = -1;
        for (int j = 0; j < uniqueCount; j++) {
            if (unique[j] == nums[i]) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            unique[uniqueCount] = nums[i];
            freq[uniqueCount] = 1;
            uniqueCount++;
        } else {
            freq[found]++;
        }
    }

    for (int i = 0; i < uniqueCount - 1; i++) {
        for (int j = i + 1; j < uniqueCount; j++) {
            if (freq[i] < freq[j]) {
                int temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
                temp = unique[i];
                unique[i] = unique[j];
                unique[j] = temp;
            }
        }
    }

    int *result = (int *)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++)
        result[i] = unique[i];
    *returnSize = k;
    free(unique);
    free(freq);

    return result;
}