void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows=matrixSize;
    int cols=matrixColSize[0];

    int zeroRows[rows];
    int zeroCols[cols];

    for( int i=0; i<rows; i++){
        zeroRows[i]=0;
    }
    for(int j=0; j<cols; j++){
        zeroCols[j]=0;
    }
    for(int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if(matrix[i][j] == 0){
                zeroRows[i]=1;
                zeroCols[j]=1;
            }
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(zeroRows[i]==1 || zeroCols[j]==1){
                matrix[i][j]=0;
            }
        }
    } 
}