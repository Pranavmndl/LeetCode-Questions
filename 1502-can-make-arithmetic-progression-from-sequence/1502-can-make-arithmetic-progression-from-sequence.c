int compare(const void* a, const void* b){
    int x= *(const int*)a;
    int y= *(const int*)b;

    if(x<y){
        return -1;
    }
    if(x>y){
        return 1;
    }
    return 0;
}
bool canMakeArithmeticProgression(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);
    int difference=arr[1]-arr[0];

    for(int i=2; i<arrSize; i++){
        if(arr[i]-arr[i-1]!= difference){
            return false;
        }
    }
    return true;
    
}