bool dfs(int** graph,int* graphColSize,int node,int color,int* colors){
    colors[node]=color;
    for(int i=0;i<graphColSize[node];i++){
        int next=graph[node][i];
        if (colors[next]==0){
            if(!dfs(graph,graphColSize,next,-color,colors))
                return false;
        }
        else if(colors[next]==color){
            return false;
        }
    }
    return true;
}
bool isBipartite(int** graph,int graphSize,int* graphColSize){
    int* colors=(int*)calloc(graphSize,sizeof(int));
    for(int i=0;i<graphSize;i++){
        if(colors[i]==0) {
            if(!dfs(graph,graphColSize,i,1,colors)){
                free(colors);
                return false;
            }
        }
    }
    free(colors);
    return true;
}