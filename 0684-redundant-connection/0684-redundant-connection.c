/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int* parent,int x){
    if(parent[x]!=x)
        parent[x]=find(parent,parent[x]);
    return parent[x];
}
bool unite(int* parent,int* rank,int a, int b) {
    int rootA=find(parent,a);
    int rootB=find(parent,b);
    if(rootA==rootB)
        return false;
    if(rank[rootA]<rank[rootB]){
        parent[rootA]=rootB;
    }
    else if(rank[rootA]>rank[rootB]){
        parent[rootB]=rootA;
    }
    else{
        parent[rootB]=rootA;
        rank[rootA]++;
    }
    return true;
}
int* findRedundantConnection(int** edges, int edgesSize,
                             int* edgesColSize, int* returnSize){

    int* parent=(int*)malloc(sizeof(int)*(edgesSize+1));
    int* rank=(int*)calloc(edgesSize+1,sizeof(int));
    for(int i=1;i<=edgesSize;i++)
        parent[i]=i;

    for(int i=0;i<edgesSize;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        if(!unite(parent,rank,u,v)) {
            int* result=(int*)malloc(sizeof(int)*2);

            result[0]=u;
            result[1]=v;
            *returnSize=2;
            free(parent);
            free(rank);
            return result;
        }
    }
    *returnSize=0;
    free(parent);
    free(rank);
    return NULL;
}