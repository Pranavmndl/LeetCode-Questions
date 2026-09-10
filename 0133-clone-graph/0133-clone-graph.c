/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node* visited[101];
struct Node* dfs(struct Node* node){
    if(node==NULL)
        return NULL;
    if(visited[node->val]!=NULL)
        return visited[node->val];
    struct Node* copy=(struct Node*)malloc(sizeof(struct Node));
    copy->val=node->val;
    copy->numNeighbors=node->numNeighbors;

    copy->neighbors=(struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);
    visited[node->val]=copy;

    for(int i=0;i<node->numNeighbors;i++){
        copy->neighbors[i]=dfs(node->neighbors[i]);
    }
    return copy;
}
struct Node* cloneGraph(struct Node* node){
    for(int i=0;i<101;i++)
        visited[i]=NULL;
    return dfs(node);
}