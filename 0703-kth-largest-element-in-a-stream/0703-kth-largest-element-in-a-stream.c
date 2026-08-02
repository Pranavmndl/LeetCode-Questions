typedef struct {
    int *heap;
    int size;
    int capacity;
} KthLargest;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(KthLargest *obj, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (obj->heap[parent] <= obj->heap[index])
            break;

        swap(&obj->heap[parent], &obj->heap[index]);
        index = parent;
    }
}

void heapifyDown(KthLargest *obj, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < obj->size &&
            obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if (right < obj->size &&
            obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&obj->heap[index], &obj->heap[smallest]);
        index = smallest;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = (KthLargest *)malloc(sizeof(KthLargest));

    obj->heap = (int *)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;

    for (int i = 0; i < numsSize; i++) {
        if (obj->size < obj->capacity) {
            obj->heap[obj->size++] = nums[i];
            heapifyUp(obj, obj->size - 1);
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/