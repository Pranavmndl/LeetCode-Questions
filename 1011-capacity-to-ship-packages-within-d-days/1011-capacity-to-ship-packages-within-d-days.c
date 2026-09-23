int canShip(int* weights, int weightsSize, int days, int capacity) {
    int current=0;
    int count=1;

    for(int i=0;i<weightsSize;i++){
        if(current+weights[i]>capacity){
            count++;
            current=weights[i];
        }else{
            current+=weights[i];
        }
    }

    return count<=days;
}

int shipWithinDays(int* weights,int weightsSize,int days) {
    int left=0,right=0;
    for(int i=0;i<weightsSize;i++){
        if(weights[i]>left)
            left=weights[i];
        right+=weights[i];
    }

    while(left<right){
        int mid=left+(right-left)/2;

        if(canShip(weights,weightsSize,days,mid))
            right=mid;
        else
            left=mid+1;
    }
    return left;
}