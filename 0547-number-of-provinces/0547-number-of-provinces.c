void dfs(int** isConnected,int n,int city,int* visited){
    visited[city]=1;
    for(int i=0;i<n;i++){
        if(isConnected[city][i]==1&&visited[i]==0){
            dfs(isConnected,n,i,visited);
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n=isConnectedSize;
    int* visited=(int*)calloc(n,sizeof(int));
    int provinces=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            provinces++;
            dfs(isConnected,n,i,visited);
        }
    }
    free(visited);
    return provinces;
    
}