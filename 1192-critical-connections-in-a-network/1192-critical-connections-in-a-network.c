/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int timer;
int *tin,*low;
int **ans;
int ansSize;

void dfs(int node,int parent,int **graph,int *graphSize){
    tin[node]=low[node]=timer++;
    for(int i=0;i<graphSize[node];i++){
        int nei=graph[node][i];
        if (nei==parent)
            continue;
        if (tin[nei]!=-1){
            if(tin[nei]<low[node])
                low[node]=tin[nei];
        }else{
            dfs(nei,node,graph,graphSize);
            if(low[nei]<low[node])
                low[node]=low[nei];

            if(low[nei]>tin[node]){
                ans[ansSize]=malloc(2*sizeof(int));
                ans[ansSize][0]=node;
                ans[ansSize][1]=nei;
                ansSize++;
            }
        }
    }
}

int** criticalConnections(int n,int** connections,int connectionsSize,
                          int* connectionsColSize,int* returnSize,
                          int** returnColumnSizes){
    
    int **graph=malloc(n*sizeof(int *));
    int *graphSize=calloc(n,sizeof(int));
    int *capacity=calloc(n,sizeof(int));

    for(int i=0;i<n;i++){
        graph[i]=NULL;
        capacity[i]=0;
    }
    for(int i=0;i<connectionsSize;i++){
        int u=connections[i][0];
        int v=connections[i][1];
        if(graphSize[u]==capacity[u]){
            capacity[u]=capacity[u]==0?2:capacity[u]*2;
            graph[u]=realloc(graph[u],capacity[u]*sizeof(int));
        }
        if(graphSize[v]==capacity[v]){
            capacity[v]=capacity[v]==0?2:capacity[v]*2;
            graph[v]=realloc(graph[v],capacity[v]*sizeof(int));
        }

        graph[u][graphSize[u]++]=v;
        graph[v][graphSize[v]++]=u;
    }

    tin=malloc(n*sizeof(int));
    low=malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        tin[i]=-1;

    ans=malloc(connectionsSize*sizeof(int *));
    ansSize=0;
    timer=0;
    dfs(0,-1,graph,graphSize);
    *returnSize=ansSize;
    *returnColumnSizes=malloc(ansSize*sizeof(int));
    for(int i=0;i<ansSize;i++)
        (*returnColumnSizes)[i]=2;
    return ans;
}