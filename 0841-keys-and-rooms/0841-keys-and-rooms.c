void dfs(int** rooms,int* roomsColSize,int room,int* visited){
    visited[room]=1;
    for(int i=0;i<roomsColSize[room];i++){
        int key=rooms[room][i];
        if(visited[key]==0){
            dfs(rooms,roomsColSize,key,visited);
        }
    }
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int* visited=(int*)calloc(roomsSize,sizeof(int));
    dfs(rooms,roomsColSize,0,visited);
    for(int i=0;i<roomsSize;i++){
        if(visited[i]==0){
            free(visited);
            return false;
        }
    }
    free(visited);
    return true;
    
}