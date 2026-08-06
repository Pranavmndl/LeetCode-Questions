int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }
    qsort(freq, 26, sizeof(int), compare);

    int maxFreq=freq[0];
    int maxCount=1;

    while (maxCount<26 && freq[maxCount]==maxFreq) {
        maxCount++;
    }
    int partCount=maxFreq-1;
    int partLength=n-(maxCount-1);
    if (partLength<0)
        partLength=0;
    int emptySlots=partCount * partLength;
    int availableTasks = tasksSize - maxFreq * maxCount;
    int idles = emptySlots - availableTasks;
    if (idles < 0)
        idles =0;
    return tasksSize + idles;
}